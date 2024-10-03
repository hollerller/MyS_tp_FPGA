/*
 * main.c
 *
 *  Created on: 2/10/2024
 *      Author: hollerller
 */


#include "xparameters.h"
#include "xgpio.h"
#include "NCO.h"


int main (void)
{
	XGpio phaseControl, rstEna;
	int i, phaseControl_test, rstEna_test;
	int pha_i[4] = {1280, 2830, 3500, 4240};
	int buttonState = 0;
	int nextState = 0;

	xil_printf("-- Start of the Program --\r\n");

	// Inicializar switches
	XGpio_Initialize(&phaseControl, XPAR_SWITCHES_DEVICE_ID);
	XGpio_SetDataDirection(&phaseControl, 1, 0xFFFFFFFF);

	// Inicializar botones
	XGpio_Initialize(&rstEna, XPAR_BUTTONS_DEVICE_ID);
	XGpio_SetDataDirection(&rstEna, 1, 0xFFFFFFFF);

	while (1){

		buttonState = XGpio_DiscreteRead(&rstEna, 1);

		//if (nextState != buttonState)

		xil_printf("button Status %x\r\n", buttonState);

		phaseControl_test = XGpio_DiscreteRead(&phaseControl, 1);

		switch (phaseControl_test){
		case 0:
			Xil_Out32((XPAR_SWITCHES_BASEADDR) + (NCO_S00_AXI_SLV_REG1_OFFSET), (u32)(pha_i[0]));
			xil_printf("Phase Increment %i\r\n", pha_i[0]);
			break;
		case 1:
			Xil_Out32((XPAR_SWITCHES_BASEADDR) + (NCO_S00_AXI_SLV_REG1_OFFSET), (u32)(pha_i[1]));
			xil_printf("Phase Increment %i\r\n", pha_i[1]);
			break;
		case 2:
			Xil_Out32((XPAR_SWITCHES_BASEADDR) + (NCO_S00_AXI_SLV_REG1_OFFSET), (u32)(pha_i[2]));
			xil_printf("Phase Increment %i\r\n", pha_i[2]);
			break;
		case 3:
			Xil_Out32((XPAR_SWITCHES_BASEADDR) + (NCO_S00_AXI_SLV_REG1_OFFSET), (u32)(pha_i[3]));
			xil_printf("Phase Increment %i\r\n", pha_i[3]);
			break;

			}
		xil_printf("Switches Status %x\r\n", phaseControl_test);

		sleep(1);

	}
}
