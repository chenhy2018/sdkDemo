#include "FrameHandler.h"

class AsyncFrameHandler public FrameHandler {
public:
    int sendVideo(char *frame, int len, double timestamp, int isKey);
    int sendAudio(char *frame, int len, double timestamp);
};
