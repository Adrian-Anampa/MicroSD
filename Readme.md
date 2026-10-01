Paso: Prueba en hardware
1. Formatea la tarjeta en FAT32 (32 GB o menos) en la PC.
2. Arranca el micro. En la UART deben salir las líneas T=...,H=... sin SD ERROR.
3. Saca la tarjeta con el micro encendido. Debe aparecer SD ERROR 3 (FR_NOT_READY) o SD ERROR 1 (FR_DISK_ERR), y el DHT11 debe seguir leyendo.
4. Abre DATOS.CSV en la PC, cópialo o vacíalo y expulsa la tarjeta de forma segura en Windows.
5. Vuelve a ponerla. El siguiente registro debe salir sin error y agregarse al final del archivo, todo sin reiniciar el micro.

PINES DEL PROYECTO:

 SPI:
    MOSI - PA7
    MISO - PA6
    SCK  - PA5
    CS   - PA4
 UART:

    TX   - PA9
    RX   - PA10
 
 DHT11
    DATA - PB12

FRECUENCIA DE ENTRADA 25MHZ Y SALIDA 100MHZ
Iniciando Medicion