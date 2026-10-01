/*
 * sd_functions.c
 *
 *  Created on: Oct 1, 2026
 *      Author: Adrian Anampa
 */


#include "sd_functions.h"
#include "string.h"

static FATFS fs;
static FIL file;
static uint8_t montado=0;

FRESULT sd_montado(void){

	FRESULT resultado;

	if(montado) return FR_OK;
	FATFS_UnLinkDriver(USERPath);
	if(FATFS_LinkDriver(&USER_Driver, USERPath) != 0) return FR_INT_ERR;

	resultado=f_mount(&fs, USERPath,1);
	if(resultado == FR_OK) montado=1;
	return resultado;

}

void sd_desmontado(void){
	f_mount(NULL,USERPath,0);
	montado=0;
}
FRESULT sd_adjuntar_csv(const char *filename, const char *header,const char *line){

	FRESULT res , rc;
	UINT bw , len;

	res= sd_montado();
	if(res!= FR_OK){
		sd_desmontado();
		return res;

	}

	res= f_open(&file, filename, FA_OPEN_APPEND | FA_WRITE);

	if(res == FR_OK){
		if( header != NULL && f_size(&file)==0){
			len=strlen(header);
			res=f_write(&file, header,len,&bw);
			if( res== FR_OK && bw!=len) res=FR_DENIED; /*tarjeta llena*/

		}
		if(res == FR_OK){
			len=strlen(line);
			res=f_write(&file, line,len,&bw);
			if( res== FR_OK && bw!=len) res=FR_DENIED;
		}
		rc=f_close(&file); /*fclose vacia el cache a la tarjeta*/
		if(res ==FR_OK) res=rc;
	}
	sd_desmontado();
	return res;
}
