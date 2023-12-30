/*
 * Bit_Math.h
 *
 * Created: 27/11/2023 15:47:49
 *  Author: Rania
 */ 


#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define F_CPU 1000000UL
#define SET_BIT(REG,BIT)            (REG|(1<<BIT))
#define CLR_BIT(REG,BIT)            (REG &(~(1<<BIT)))
#define TOG_BIT(REG,BIT)            (REG|(REG^(1<<BIT)))
#define READ_BIT(REG,BIT)           ((REG>>BIT)&1)


#define SET_HIGH_NIB(REG)           (REG|(0b1111<<4))

#define CLR_HIGH_NIB(REG)           (REG &(~(0b1111<<4)))

#define GET_HIGH_NIB(REG)           ((REG) >> 4)

#define TGL_HIGH_NIB(REG)           (REG|(REG^(0b1111<<4)))

#define SET_LOW_NIB(REG)            (REG|(0b1111<<0))

#define CLR_LOW_NIB(REG)            (REG &(~(0b1111<<0)))

#define GET_LOW_NIB(REG)            ((REG) & 0x0F)

#define TGL_LOW_NIB(REG)            (REG|(REG^(0b1111<<0)))

#define ASSIGN_REG(REG,VALUE)       ((REG) = (VALUE))

#define ASSIGN_HIGH_NIB(REG,VALUE)  (REG|(VALUE<<4))

#define ASSIGN_LOW_NIB(REG,VALUE)   (REG|(VALUE<<0))


#define RSHFT_REG(REG, NO)          (REG >> NO)
#define LSHFT_REG(REG, NO)          (REG << NO)
#define CRSHFT_REG(REG, NO)         ((REG >> NO)|REG << (8- NO))
#define CLSHFT_REG(REG,NO)          ((REG << NO)|REG >> (8- NO))



#endif /* BIT_MATH_H_ */