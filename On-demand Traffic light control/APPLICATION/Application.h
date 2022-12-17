/********************		Author: Ahmed Elshety	**************/
/********************		Layer: Application		**************/
/********************		SWC	 : Application		**************/
/********************		Date : 01-12-2022		**************/
/*****************************************************************/
/*****************************************************************/

#ifndef APPLICATION_H_
#define APPLICATION_H_



#define TurnOFF        0
#define TurnON         1

void AppInit(void);

void AppStart(void);

void APP_voidBlinkYellowCarLed(void);

void APP_voidBlinkYellowCarAndHumanLed(void);

void APP_voidCarTurnOnOffGreenLed(u8 Copy_u8State);

void APP_voidCarTurnOnOffRedLed(u8 Copy_u8State);

void APP_voidHumanTurnOnOffGreenLed(u8 Copy_u8State);

void APP_voidHumanTurnOnOffRedLed(u8 Copy_u8State);

void APP_voidNormalCarMode(void);

void APP_voidNormalHumanMode(void);



#endif /* _APPLICATION_H_ */
