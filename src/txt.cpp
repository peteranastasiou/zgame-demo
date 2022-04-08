
#include "txt.hpp"
#include "wasm4.h"

namespace txt {

// Helper for displaying text using wasm4
void render_(char const * line, int lineNum, int y) {
    text(line, 4, y + lineNum * TEXT_HEIGHT);
}

uint8_t reflow(char const * msg, int y, bool dryRun) {
    int const LINE_LENGTH = 19;
    char lineBuffer[LINE_LENGTH+1];

    int const MAX_WORD_LEN_TO_KEEP = 5; // reflow words up to this length.

    uint8_t numLines = 1;
    int strIdx = 0;
    int lastSpaceInLine = 0;
    int lastSpaceInStr = 0;
    int lineStart = 0;
    int lineIdx = 0;
    while(true){
        // next character
        char c = msg[strIdx];

        if(c == '\0') {
            // end of string
            // display remaining text in buffer
            lineBuffer[lineIdx]= '\0';
            if( !dryRun ) render_(lineBuffer, numLines-1, y);
            return numLines;
        }
        else if(c == ' ') {
            // record new word boundary
            lastSpaceInStr = strIdx;
            lastSpaceInLine = lineIdx;
        }
        
        lineBuffer[lineIdx] = c;
        strIdx ++;

        // Should we break off a new line?
        if( lineIdx == LINE_LENGTH || c == '\n' ){
            int lastWordLength = lineIdx - lastSpaceInLine;

            if( c == '\n' ){
                lineBuffer[lineIdx] = '\0';
            }
            else if( lastWordLength < MAX_WORD_LEN_TO_KEEP ){
                // rewind up to last space, reset counters
                lineBuffer[lastSpaceInLine] = '\0';
                strIdx = lastSpaceInStr+1;
            }
            else {
                // split word with '-'
                lineBuffer[LINE_LENGTH-1] = '-';
                lineBuffer[LINE_LENGTH] = '\0';
                // rewind before '-'
                strIdx -= 2;
            }
            if( !dryRun ) render_(lineBuffer, numLines-1, y);
            lineIdx = 0;
            lastSpaceInLine = 0;
            lastSpaceInStr = strIdx;
            numLines ++;
        }
        else {
            lineIdx ++;
        }
    }
}

} // namespace txt
