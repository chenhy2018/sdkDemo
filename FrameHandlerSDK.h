class FrameHandler;

class FrameHandlerSDK {
public:
    FrameHandlerSDK() {
        handler = 0;
    }
    virtual bool start() = 0;
    virtual bool stop() = 0;
    void setHandler(FrameHandler *handler) {
        this->handler = handler;
    }

private:
    FrameHandler *handler;
};

