
#include "Mascota.h"


void HardcodeMascotas(eMascotas mascota[],int tam) {
    int i;
    int idMascota[11]={2000,2001,2002,2003,2004,2005,2006,2007,2008,2009,2010};
    int idDuenio[11]={1000,1000,1001,1001,1001,1002,1002,1003,1004,1004,1004};
    char nombre[11][51]={{"blanca"},{"tigres"},{"machas"},{"Potter"},{"michifusi"},{"beto"},{"nenita"},{"Manchita"},{"Miox"},{"Micheeex"},{"maid"}};
    char tipo[11][51]={{"Gato"},{"Gato"},{"Perro"},{"Perro"},{"Gato"},{"Perro"},{"Raro"},{"Perro"},{"Gato"},{"Gato"},{"Perro"}};
    int idRaza[11]={3000,3001,3002,3003,3000,3000,3001,3002,3003,3000,3001};
    //char raza[11][51]={{"Persa"},{"Callejero"},{"Pug"},{"Pitbull"},{"Persa"},{"Pitbull"},{"Reptil"},{"Labrador"},{"Persa"},{"Persa"},{"Bulldog"}};
    int edad[11]={1,2,1,2,3,4,4,1,2,4,3};
    float peso[11]={5.35,3.25,4.30,7.00,6.35,3.64,10.23,7.85,4.43,4.96,3.79};
    char sexo[11]={'F','F','F','F','F','M','F','M','M','M','M'};
    int estado[11]={1,1,1,1,1,1,1,1,1,1,1};

    for(i=0;i<11;i++) {
        mascota[i].idMascota=idMascota[i];
        mascota[i].idDuenio=idDuenio[i];
        mascota[i].idRaza=idRaza[i];
        strcpy(mascota[i].nombre,nombre[i]);
        strcpy(mascota[i].tipo,tipo[i]);
        //strcpy(mascota[i].raza,raza[i]);
        mascota[i].edad=edad[i];
        mascota[i].peso=peso[i];
        mascota[i].sexo=sexo[i];
        mascota[i].estado=estado[i];
    }
}
void inicializarMascota(eMascotas mascota[], int tam){
    int i;
    for(i=0;i<tam;i++){
        mascota[i].estado = LIBRE;
        mascota[i].idMascota=0;
    }
}
void mostrarMascota(eMascotas mascota[],int tam) {
    int i;
    printf("\t\tID\t\tNOMBRE\t\tTIPO\t\tRAZA\tEDAD\tPESO\tSEXO\n\n\n");
    for(i=0;i<tam;i++) {
        if(mascota[i].estado==OCUPADO) {
            mostrarUnMascota(mascota[i]);
            }
        }
}
void mostrarUnMascota(eMascotas miMascota){

    printf("%19d%19s%14s%16d%8d%8.2f%8c\n",miMascota.idMascota,miMascota.nombre,
                                    miMascota.tipo,miMascota.idRaza,miMascota.edad,miMascota.peso,miMascota.sexo);
}
int  buscarLibreMascota(eMascotas listaMascota[], int tam){
    int i;
    int retorno=-1;
    for(i=0;i<tam;i++){
        if(listaMascota[i].estado==LIBRE){
            retorno = i;
            break;
        }
    }
return retorno;
}
int bajaMascota(eMascotas mascota[],int tam) {

    int aux;
    int i;
    int retorno = -1;
    char seguir;
    do{
        mostrarMascota(mascota,tam);
        aux=GetInt("\nIngrese id de mascota: ");
        for(i=0;i<tam;i++){
            if(mascota[i].idMascota==aux && mascota[i].estado==OCUPADO) {
                printf("\nSe encontro la mascota, se dara de baja\n");
                retorno = 1;
                mascota[i].estado=LIBRE;
            }
        }
        if(retorno == -1){
            printf("\n no se encontro lo siento\n");
        }
    seguir=GetChar("DESEAS SEGUIR (s/n):");
    }while(seguir == 's' || seguir == 'S');

return retorno;
}
void modificarMascota(eMascotas mascota[],int tam) {
    int index;
    int i;
    int opcion;
    int retorno=0;
    index=GetInt("\nINGRESE ID DE MASCOTA: ");
    for(i=0; i<tam; i++) {
        if(mascota[i].idMascota==index && mascota[i].estado==OCUPADO) {
            do {
                retorno = 1;
                printf("*************************\n");
                printf("\nNombre: %s",mascota[i].nombre);
                printf("\nTipo: %s",mascota[i].tipo);
                printf("\nRaza: %d",mascota[i].idRaza);
                printf("\nEdad: %d",mascota[i].edad);
                printf("\nPeso: %.2f",mascota[i].peso);
                printf("\nSexo: %c",mascota[i].sexo);
                printf("\n*************************\n");
                printf("1).Nombre\n");
                printf("2).Tipo\n");
                printf("3).Raza\n");
                printf("4).Edad\n");
                printf("5).Peso\n");
                printf("6).Sexo\n");
                printf("7).Salir\n");
                opcion=GetInt("ingrese un opcion a modificar\n");
                switch(opcion) {
                    case 1:
                        GetString("Ingrese nombre: ",mascota[i].nombre);
                        break;
                    case 2:
                        GetString("Ingrese tipo: ",mascota[i].tipo);
                        break;
                    case 3:
                        GetString("Ingrese raza: ",mascota[i].raza);
                        break;
                    case 4:
                        mascota[i].edad=GetInt("Ingrese Edad: ");
                        break;
                    case 5:
                        mascota[i].peso=GetFloat("Ingrese peso: ");
                        break;
                    case 6:
                        mascota[i].sexo=GetChar("ingrese sexo (F/M):");
                        break;
                }
            }while(opcion!=7);
        }
    }
    if(retorno == 0){
        printf("\nLO SIENTO NO SE ENCONTRO LA IDE \n");
    }
}
void listarMascotastipoenParticular(eMascotas listasMascotas[], int tam_mascotas){
    int indiceMascotas;
    int opcion;

    do{ system("cls");
        printf("\t\t\t**************************************************************\n");
        printf("\t\t\t>-----------LISTA MASCOTA POR TIPO EN PARTICULAR-------------<\n");
        printf("\t\t\t**************************************************************\n");
        printf("\n\n1.LISTAS DE PERROS\n");
        printf("2.LISTAS DE GATOS\n");
        printf("3.LISTAS DE RAROS\n");
        printf("4.SALIR\n");
        opcion=validate_option("\nIngrese una opcion: ");
        switch (opcion){
            case 1:
                printf("\t\t----------------------------------TIPO PERRO--------------------------------\n\n");
                for(indiceMascotas=0; indiceMascotas<tam_mascotas; indiceMascotas++){
                    if(strcmpi(listasMascotas[indiceMascotas].tipo,"Perro")==0){
                        mostrarUnMascota(listasMascotas[indiceMascotas]);
                    }
                }
                break;
            case 2:
                printf("\t\t----------------------------------TIPO GATO---------------------------------\n\n");
                for(indiceMascotas=0; indiceMascotas<tam_mascotas; indiceMascotas++){
                    if(strcmpi(listasMascotas[indiceMascotas].tipo,"Gato")==0){
                        mostrarUnMascota(listasMascotas[indiceMascotas]);
                    }
                }
                break;
            case 3:
                printf("\t\t----------------------------------TIPO RARO---------------------------------\n\n");
                for(indiceMascotas=0; indiceMascotas<tam_mascotas; indiceMascotas++){
                    if(strcmpi(listasMascotas[indiceMascotas].tipo,"Raro")==0){
                        mostrarUnMascota(listasMascotas[indiceMascotas]);
                    }
                }
                break;
            case 4:
                printf("chau;\n");
                break;
            default:
                printf("Ingrese una opcion valida\n");
                break;
        }
    system("pause");
    }while(opcion!=4);
}
float promediodeEdadesMascota(eMascotas listasMascotas[], int tam_Mascotas){

    int indiceMascota;
    int sumaEdades = 0;
    int contadorid = 0;
    float promedioEdades;
    for(indiceMascota= 0; indiceMascota<tam_Mascotas; indiceMascota++){
        if(listasMascotas[indiceMascota].estado == OCUPADO){
            sumaEdades = sumaEdades + listasMascotas[indiceMascota].edad;
            contadorid++;
        }
    }
    promedioEdades= (float)sumaEdades/contadorid;
return promedioEdades;
}
void promediodePortipo(eMascotas listasMascotas[], int tam_Mascota){

    int opcion;
    do{

        char tipo[20]= " ";
        printf("1.PROMEDIO PERRO\n");
        printf("2.PROMEDIO GATO\n");
        printf("3.PROMEDIO RARO\n");
        printf("4.SALIR\n");
        opcion = validate_option("Ingrese una opcion:  ");
        switch(opcion){
            case 1:
                printf("PROMEDIO DE PERRO\n");
                strcpy(tipo,"Perro");
                sumaEdadesdeMascotas(listasMascotas,tam_Mascota,tipo);
                break;
            case 2:
                printf("PROMEDIO DE GATOS\n");
                strcpy(tipo,"Gato");
                sumaEdadesdeMascotas(listasMascotas,tam_Mascota,tipo);
                break;
            case 3:
                printf("PROMEDIO DE RARO\n");
                strcpy(tipo,"Raro");
                sumaEdadesdeMascotas(listasMascotas,tam_Mascota,tipo);
                break;
            case 4:
                printf("hasta luego\n");
                break;
            default:
                printf("OPCION NO VALIDAD");
                break;
        }
    }while(opcion!=4);
}
void sumaEdadesdeMascotas(eMascotas listasMascotas[], int tam_Mascota, char tipo[]){
    int indiceMascota;
    int sumaEdades=0;
    int contadorid=0;
    float promedioPorTipo;
    for(indiceMascota = 0; indiceMascota<tam_Mascota ; indiceMascota++){
        if(listasMascotas[indiceMascota].estado == OCUPADO){
            if(strcmpi(listasMascotas[indiceMascota].tipo,tipo)==0){
                mostrarUnMascota(listasMascotas[indiceMascota]);
                sumaEdades = sumaEdades + listasMascotas[indiceMascota].edad;
                contadorid++;
            }
        }
    }
    promedioPorTipo=(float)sumaEdades/contadorid;
    printf("EL PROMEDIO DE LAS EDADE DE LAS MASCOTA ES: %.2f \n", promedioPorTipo);

}
void ordenarMascotasPorTIpo(eMascotas listasMascotas[], int tam_clientes){

    int indice1;
    int indice2;
    eMascotas auxMascotas;
    for(indice1=0; indice1<tam_clientes-1; indice1++) {
        for(indice2=indice1+1; indice2<tam_clientes; indice2++) {
            if(strcmp(listasMascotas[indice1].tipo,listasMascotas[indice2].tipo)>0) {
                auxMascotas = listasMascotas[indice1];
                listasMascotas[indice1] = listasMascotas[indice2];
                listasMascotas[indice2] = auxMascotas;
            }
        }
    }
}













