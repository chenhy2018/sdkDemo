class FrameHandler;

class SipHandler {
public:
    static void OnCallStateChange(int callId, SipInviteState state, SipAnswerCode code);

public:
    SipHandler() {
        SipCallBack cb;
        cb.OnIncomingCall  = &cbOnIncomingCall;
        cb.OnCallStateChange = &cbOnCallStateChange;
        cb.OnRegStatusChange = &cbOnRegStatusChange;
        SipCreateInstance(&cb);
        sleep(2);
        nid1 = SipAddNewAccount("1001", "1001", "123.59.204.198");
        SipRegAccount(nid1, 1);
        handler = 0;
    }

    void setHandler(FrameHandler *handler) {
        this->handler = handler
    }

private:
    static FrameHandler *handler;
};
