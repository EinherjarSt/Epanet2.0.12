// CallingApp.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <stdio.h>
#include <errno.h>
#include "epanet2.h"
void stepbystep() {
    long  t = 0;
    long tstep = 1;
    ENopenH();
    /* Iterate over all demands */
    ENinitH(0);
    do
    {
        /* Set nodal demand, initialize hydraulics, make a */
        /* single period run, and retrieve pressure */
        ENrunH(&t);
        ENnextH(&tstep);
    } while (tstep > 0);

    /* Close hydraulics solver & toolkit */
    ENcloseH();
}

void runAll() {
    int err = ENsolveH();
    ENsavehydfile("resource/result");
    if (err) {
        char txt[100];
        ENgeterror(err, txt, 100);
        perror(txt);
    }
}

int main()
{
    /* Open the EPANET toolkit & hydraulics solver */
    ENopen("resource/hanoi-Frankenstein-optimized.INP", "resource/report.rpt", "jajaja");
    //stepbystep();
    //runAll();
    ENclose();

    char txt[100];
    //const char* name = tmpnam(NULL);
    //printf(name);
    tmpnam(txt);
    printf(txt);

    return 0;
}


// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
