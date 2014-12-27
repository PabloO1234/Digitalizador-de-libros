//Esto es especifico de la librería FSM usada
// https://github.com/IgorReal/SECUduino/tree/master/FSM%20Library

#ifndef myStates_H
#define myStates_H


//Declaracion de las funciones
//extern void func44(void);
extern void func1(void);
extern void func2(void);
extern void func3(void);
extern void func4(void);
extern void func5(void);
extern void func6(void);
extern void func7(void);
//extern void func3(void);
extern void func8(void);
extern void func9(void);
extern void func10(void);
extern void func11(void);
extern void func12(void);
extern void func13(void);
extern void func14(void);
extern void func15(void);
extern void func16(void);
extern void func17(void);
//extern void func14(void);
//extern void func15(void);

//Declaracion del nombre de ESTADOS y de EVENTOS

#define STATE1  	0x01
#define STATE2  	0x02
#define STATE3  	0x03
#define STATE4  	0x04
#define STATE5  	0x05
#define STATE6  	0x06
#define STATE7  	0x07
#define STATE8  	0x08
#define STATE9  	0x09
#define STATE10  	0x010
#define STATE11  	0x011
#define STATE12  	0x012
#define STATE13  	0x013
#define STATE14  	0x014
#define STATE15  	0x015
#define STATE16  	0x016
#define STATE17  	0x017




#define PRESSURE     	0x018
#define FC_UP_V     	0x019

	
	

// Estructuras descriptivas de mi diagrama de flujo
const FSMClass::FSM_State_t FSM_State[] PROGMEM= {
// STATE,STATE_FUNC
//{STATE44,func44},
{STATE1,func1},
{STATE2,func2},
{STATE3,func3},
{STATE4,func4},
{STATE5,func5},
{STATE6,func6},
{STATE7,func7},
//{STATE3,func3},
{STATE8,func8},
{STATE9,func9},
{STATE10,func10},
{STATE11,func11},
{STATE12,func12},
{STATE13,func13},
{STATE14,func14},
{STATE15,func15},
{STATE16,func16},
{STATE17,func17},
//{STATE15,func15},
};

const FSMClass::FSM_NextState_t FSM_NextState[] PROGMEM= {
// STATE,EVENT,NEXT_STATE
//{STATE44,0,STATE55},
{STATE1,FC_UP_V,STATE2},
{STATE2,3,STATE3},
{STATE3,4,STATE4},
{STATE4,5,STATE5},
{STATE5,6,STATE6},
{STATE6,PRESSURE,STATE7},
{STATE7,8,STATE8},
//{STATE3,4,STATE4},
{STATE8,9,STATE9},
{STATE9,10,STATE10},
{STATE10,11,STATE11},
{STATE11,12,STATE12},
{STATE12,13,STATE13},
{STATE13,FC_UP_V,STATE14},
{STATE14,15,STATE15},
{STATE15,16,STATE16},
{STATE16,17,STATE17},
{STATE17,1,STATE1},
//{STATE14,15,STATE15},
//{STATE15,55,STATE55},
};


//Macros para el cálculo de los tamaños de las estructuras
//NO MODIFICAR
#define nStateFcn		sizeof(FSM_State)/sizeof(FSMClass::FSM_State_t)
#define nStateMachine		sizeof(FSM_NextState)/sizeof(FSMClass::FSM_NextState_t)

#endif

