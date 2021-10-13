#ifndef LCD_INTERFACE_H
#define LCD_INTERFACE_H

#define MAX_SIZE 1000
void LCD_voidSendCommand(u8 Copy_u8Command);

void LCD_voidSendData(u8 Copy_u8Data);

void LCD_voidInit(void);

void LCD_void4BitInit(void);

void LCD_voidGoToXY(u8 Copy_u8XPos ,u8 Copy_u8YPos);

void LCD_voidClear(void);

void LCD_voidSendCustomCharacter(u8*Copy_pu8CharacterArray,u8 Copy_u8PatternNum, u8 Copy_u8XPos,u8 Copy_u8YPos );

void LCD_voidSendString(const char* Copy_pcString);

void LCD_voidWriteNumber(u32 Copy_u32num, u8 Copy_u8XPos,u8 Copy_u8Ypos);

#endif
