#ifndef THDuinoBtn_h
#define THDuinoBtn_h

class  THDuinoBtn
{
	unsigned char m_ucStatus;

public:
	enum THD_BTN_ST{
    _THD_BTN_UP,
    _THD_BTN_PRESS,
    _THD_BTN_HOLD,
    _THD_BTN_RELEASE
  };

	THDuinoBtn(void);
	~THDuinoBtn(void);
	void vUpdate(bool bPin);
	bool bUp(void);
	bool bPress(void);
	bool bHold(void);
	bool bRelease(void);
	unsigned char ucGetStatus(void);
};
#endif
