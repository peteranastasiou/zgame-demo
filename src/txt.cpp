
#include "txt.hpp"
#include "wasm4.h"

namespace txt {

// Helper for displaying text using wasm4
void render_(char const * line, int lineNum, int y) {
    text(line, 4, y + lineNum * TEXT_HEIGHT);
}

uint8_t reflow(char const * msg, int y, int len, bool dryRun) {
    int const LINE_LENGTH = 19;
    char lineBuffer[LINE_LENGTH+1];

    int const MAX_WORD_LEN_TO_KEEP = 10; // reflow words up to this length.

    uint8_t numLines = 1;
    int strIdx = 0;
    int lastSpaceInLine = 0;
    int lastSpaceInStr = 0;
    int lineStart = 0;
    int lineIdx = 0;
    while(true){
        // next character
        char c = msg[strIdx];

        if( c == '\0' || strIdx == len ) {
            // end of string
            // display remaining text in buffer
            lineBuffer[lineIdx]= '\0';
            if( !dryRun ) render_(lineBuffer, numLines-1, y);
            return numLines;
        }
        else if( c == ' ' ) {
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
                // we know word is at least MAX_WORD_LEN_TO_KEEP already, so rewind a little
                // this is a simple way of ensuring at least >3 chars reflowed to the next line
                int const REWIND = 3;
                lineBuffer[LINE_LENGTH-REWIND] = '-';
                lineBuffer[LINE_LENGTH-REWIND+1] = '\0';
                // rewind before '-'
                strIdx -= REWIND+1;
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
