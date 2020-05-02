/*
THControlPanel by Alvpjh
https://github.com/alvpjh/THControlPanel
02/05/2020
*/

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
