





void TIM1_SetICUValue(uint16 u16ICUValCpy)
{
	ICR1L = 0 ;
	ICR1H = 0 ;

	ICR1L |= u16ICUValCpy;
	ICR1H |= u16ICUValCpy<< 8;
}
