/*
 * Macros.h
 *
 * Created: 11/12/2022 2:08:18 PM
 *  Author: Hossam Elzhar
 */ 


#ifndef MACROS_H_
#define MACROS_H_


#define SET_REG(Reg)             (Reg=0xFF)
#define CLEAR_REG(Reg)           (Reg=0x00)
#define TOGGLE_REG(Reg)          (Reg^=0xFF)
#define ASSIGN_REG(Reg,Value)    (Reg=Value)
#define SET_BITS_REG(Reg,Mask)   (Reg|=(Mask))
#define CLEAR_BITS_REG(Reg,Mask) (Reg=(Reg&(~Mask)))
#define SET_BIT(Reg,bit)         (Reg|=(1<<bit))
#define CLEAR_BIT(Reg,bit)       (Reg=(Reg&(~(1<<bit))))
#define TOGGLE_BIT(Reg,bit)      (Reg^=(1<<bit))
#define CHECK_BIT(Reg,bit)       ((Reg>>bit)&1)


#endif /* MACROS_H_ */