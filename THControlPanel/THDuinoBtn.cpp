#include "THDuinoBtn.h"

THDuinoBtn::THDuinoBtn(void)
{
	m_ucStatus = _THD_BTN_UP;
}

THDuinoBtn::~THDuinoBtn(void)
{
}

bool THDuinoBtn::bUp(void){
	if(m_ucStatus == _THD_BTN_UP)     return true;
	return false;
}
bool THDuinoBtn::bPress(void){
	if(m_ucStatus == _THD_BTN_PRESS)   return true;
	return false;
}
bool THDuinoBtn::bHold(void){
	if(m_ucStatus == _THD_BTN_HOLD)    return true;
	return false;
}
bool THDuinoBtn::bRelease(void){
	if(m_ucStatus == _THD_BTN_RELEASE) return true;
	return false;
}

void THDuinoBtn::vUpdate(bool bPin)
{
  switch(m_ucStatus){
      case _THD_BTN_UP      : if(bPin)  m_ucStatus = _THD_BTN_PRESS;  else m_ucStatus = _THD_BTN_UP;      break;
      case _THD_BTN_PRESS   : if(bPin)  m_ucStatus = _THD_BTN_HOLD;   else m_ucStatus = _THD_BTN_RELEASE; break;
      case _THD_BTN_HOLD    : if(bPin)  m_ucStatus = _THD_BTN_HOLD;   else m_ucStatus = _THD_BTN_RELEASE; break;
      case _THD_BTN_RELEASE : if(bPin)  m_ucStatus = _THD_BTN_PRESS;  else m_ucStatus = _THD_BTN_UP;      break;
    }
}

unsigned char THDuinoBtn::ucGetStatus(void)
{
	return m_ucStatus;
}
