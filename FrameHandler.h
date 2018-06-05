class SipHandler;
class FrameHandlerSDK;

class FrameHandler {
public:
    virtual int sendVideo(char *frame, int len, double timestamp, int isKey) = 0;
    virtual int sendAudio(char *frame, int len, double timestamp) = 0;

    FrameHandler() {
        sdk = 0;
        sip = 0;
    }

    void setSDK(FrameHandlerSDK *sdk) {
        this->sdk = sdk;
    }
    void setSip(Sip *sip) {
        this->sip = sip;
    }

private:
    FrameHandlerSDK *sdk;
    SipHandler *sip;
};
