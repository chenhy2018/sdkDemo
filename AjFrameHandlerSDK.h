#include "FrameHandlerSDK.h"

class AjFrameHandlerSDK public FrameHandlerSDK {
public:
    static int VideoCallback(char *frame, int len, int isKey, double timestamp,
        unsigned long frameIndex, unsigned long keyFrameIndex, void *context);

    static int AudioCallback(char *frame, int len, double timestamp,
        unsigned long frameIndex, void *context);

public:
    AjFrameHandlerSDK();
    bool start();
    bool stop();
    void setHandler(FrameHandler *handler);

private:
    void init();
    bool audio();

private:
    int inited;
    bool started;
};
