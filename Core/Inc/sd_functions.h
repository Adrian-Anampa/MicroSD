/*
 * sd_functions.h
 *
 *  Created on: Oct 1, 2026
 *      Author: Adrian Anampa
 */

#ifndef INC_SD_FUNCTIONS_H_
#define INC_SD_FUNCTIONS_H_

#include "fatfs.h"

FRESULT sd_montado(void);
void sd_desmontado(void);

/*Monta agrega 'line' al final del archivo (escribe 'header' si el archivo es nuevo),
 * cierra y desmonta
 */
FRESULT sd_adjuntar_csv(const char *filename, const char *header,const char *line);


#endif /* INC_SD_FUNCTIONS_H_ */
