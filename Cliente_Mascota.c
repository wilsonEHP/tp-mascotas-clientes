#include "Cliente_Mascota.h"


void mostrarMascotasConSusCliente(eCliente cliente[],int tamCliente,eMascotas mascotas[], int tamMascota){

    int indiceCliente;
    int indiceMascota;

    printf("\t\tNOMBRE\t\tTIPO\t\tRAZA\t\tEDAD\t\tPESO\t\tSEXO\t\tNOMBRE\n\n");
    for(indiceMascota=0; indiceMascota<tamMascota; indiceMascota++) {
        if(mascotas[indiceMascota].estado==OCUPADO) {
            for(indiceCliente=0; indiceCliente<tamCliente; indiceCliente++) {
                if(cliente[indiceCliente].idCliente == mascotas[indiceMascota].idDuenio) {

                    printf("%22s%14s%17d\t%12d%16.2f\t%12c%18s\n", mascotas[indiceMascota].nombre,mascotas[indiceMascota].tipo,
                                            mascotas[indiceMascota].idRaza, mascotas[indiceMascota].edad,
                                            mascotas[indiceMascota].peso,mascotas[indiceMascota].sexo,
                                            cliente[indiceCliente].nombre);
                    break;
                }
            }

        }
    }
}

void mostrarClientesConSusMascotas(eCliente cliente[],int tamCliente,eMascotas mascota[],int tamMascota){
    int indiceCientes;
    int indiceMascotas;
    printf("\t\tID\t\tNOMBRE\t\tTIPO\t\tRAZA\tEDAD\tPESO\tSEXO\n\n\n");
    for(indiceCientes=0; indiceCientes<tamCliente; indiceCientes++) {
        if(cliente[indiceCientes].estado==OCUPADO){
            printf("clientes: %s\n", cliente[indiceCientes].nombre);
            for(indiceMascotas=0; indiceMascotas<tamMascota; indiceMascotas++) {
                if(mascota[indiceMascotas].idDuenio == cliente[indiceCientes].idCliente) {
                          mostrarUnMascota(mascota[indiceMascotas]);
                }
            }
        }
    }
}

int altaMascotaConclientes(eMascotas mascota[], int tamMascota,eCliente clientes[], int tamCliente,int contador) {

    int indexCliente;
    int indexLibre;
    indexLibre=buscarLibreMascota(mascota,tamMascota);
    int retorno=-1;
    if(indexLibre!=-1) {
        GetString("Ingrese el Nombre: ",mascota[indexLibre].nombre);
        do{
            GetString("Ingrese el Tipo disponible (Perro Gato Raro) : ",mascota[indexLibre].tipo);
        }while((strcmpi(mascota[indexLibre].tipo,"Perro")==0||strcmpi(mascota[indexLibre].tipo,"Gato")==0||strcmpi(mascota[indexLibre].tipo,"Raro")==0)!=1);

        //GetString("Ingrese la Raza: ",mascota[indexLibre].raza);
        mascota[indexLibre].idRaza=GetInt("Ingrese la Raza: ");
        mascota[indexLibre].edad=GetInt("Ingrese Edad: ");
        mascota[indexLibre].peso=GetFloat("Ingrese Peso: ");
        mascota[indexLibre].sexo=GetChar("Ingrese sexo ('M'o'F'): ");
        printf("\t\t\tCLIENTES DISPONIBLES\n\n");
        for (indexCliente=0; indexCliente<tamCliente;indexCliente++){
            if(clientes[indexCliente].estado==OCUPADO){
                printf("\t\t%12d %14s\n",clientes[indexCliente].idCliente,clientes[indexCliente].nombre);
            }
        }
        mascota[indexLibre].idDuenio=GetInt("Ingrese ID del duenio: ");
        mascota[indexLibre].idMascota=GenerarId(2010,contador);
        mascota[indexLibre].estado=OCUPADO;
        printf("Agregado exitosamente\n");
        retorno=indexLibre;
        }
return retorno;
}


int EliminarDuenio(eCliente listaClientes[],int tam_Clientes,eMascotas listasMascotas[],int tam_Mascotas) {

    int idClienteAeliminar;
    int retornoBandera=-1;
    int indiceCliente;
    int indiceMascota;
    do{
        mostrarCliente(listaClientes,tam_Clientes);
        idClienteAeliminar= GetInt("\nIngrese ID del cliente: ");
        for(indiceCliente=0; indiceCliente<tam_Clientes; indiceCliente++) {
            if(listaClientes[indiceCliente].estado==OCUPADO && idClienteAeliminar==listaClientes[indiceCliente].idCliente) {
                listaClientes[indiceCliente].estado=LIBRE;
                for(indiceMascota=0; indiceMascota<tam_Mascotas; indiceMascota++){
                    if(listasMascotas[indiceMascota].idDuenio == idClienteAeliminar){
                        listasMascotas[indiceMascota].estado = LIBRE;
                        retornoBandera=0;
                    }
                }
            }
        }
    }while(retornoBandera==-1);
    printf("ELIMICION EXITOSA \n");

return retornoBandera;
}

void mostrarClienteConMasUnaMascota(eCliente listasCliente[], int tam_clientes, eMascotas listasMascota[], int tam_Mascota){
    Clientes_Mascota auxClienteMascota[tam_clientes];
    int indiceClientes;

    inicializarClientes_Mascotas(auxClienteMascota,tam_clientes,listasCliente);
    contadorDeMascotaporClientes(listasCliente,tam_clientes,listasMascota,tam_Mascota,auxClienteMascota);
    printf("\tID-----------NOMBRE---------CANTIDAD MASCOTA\n\n");
    for(indiceClientes=0; indiceClientes<tam_clientes; indiceClientes++){
        if (auxClienteMascota[indiceClientes].cantidadMascota> 1 ){
            printf("\t%d  %14s  %14d\n\n",auxClienteMascota[indiceClientes].idCliente, listasCliente[indiceClientes].nombre,
                                    auxClienteMascota[indiceClientes].cantidadMascota );
        }

    }
}

void mostrarMascotasMayordetres(eCliente listasClientes[],int tam_Clientes, eMascotas listaMascotas[], int tam_Mascota){

    int indiceCliente;
    int indiceMascota;
    for(indiceMascota=0; indiceMascota<tam_Mascota; indiceMascota++) {

        if(listaMascotas[indiceMascota].estado==OCUPADO && listaMascotas[indiceMascota].edad>=3) {
            printf("******************************************\n");
            printf(">             %s             \n",listaMascotas[indiceMascota].nombre);
            printf("******************************************\n");
            for(indiceCliente=0; indiceCliente<tam_Clientes; indiceCliente++) {

                if(listasClientes[indiceCliente].idCliente == listaMascotas[indiceMascota].idDuenio) {

                    printf("%20s%20d%8d%14.2f%8c%20s\n\n",listaMascotas[indiceMascota].tipo,
                                                        listaMascotas[indiceMascota].idRaza, listaMascotas[indiceMascota].edad,
                                                        listaMascotas[indiceMascota].peso,listaMascotas[indiceMascota].sexo,
                                                        listasClientes[indiceCliente].nombre);
                                                        break;
                }
            }

        }
    }
}


void ordenarDuenioosPorcantida(eMascotas listamascotas[], int tam_Mascota, eCliente listaclientes[], int tam_clientes){

    int indice_I;
    int indice_J;
    Clientes_Mascota auxClienteMascota[tam_clientes];
    Clientes_Mascota auxiliar;
    eCliente auxiliarClientes;

    inicializarClientes_Mascotas(auxClienteMascota,tam_clientes,listaclientes);

    contadorDeMascotaporClientes(listaclientes,tam_clientes,listamascotas,tam_Mascota,auxClienteMascota);

        for(indice_I=0; indice_I<tam_clientes-1; indice_I++) {
            for(indice_J=indice_I+1; indice_J<tam_clientes; indice_J++) {
                if(auxClienteMascota[indice_I].cantidadMascota<auxClienteMascota[indice_J].cantidadMascota){
                    auxiliar = auxClienteMascota[indice_I];
                    auxClienteMascota[indice_I] = auxClienteMascota[indice_J];
                    auxClienteMascota[indice_J] = auxiliar;

                    auxiliarClientes = listaclientes[indice_I];
                    listaclientes[indice_I]= listaclientes[indice_J];
                    listaclientes[indice_J]= auxiliarClientes;
                }
            }
        }
        printf("-------------------------------------\n");
        printf(" NOMBRE DUENIO------CANTIDAD MASCOTAS\n");
        printf("-------------------------------------\n");
        for(indice_I = 0; indice_I<tam_clientes; indice_I++){
            if(listaclientes[indice_I].estado ==OCUPADO){
                printf(" %15s,%15d\n",listaclientes[indice_I].nombre,auxClienteMascota[indice_I].cantidadMascota);
                printf("-------------------------------------\n");
            }
        }
}

void inicializarClientes_Mascotas(Clientes_Mascota auxClienteMascota[], int tam_clientes, eCliente listaCliente[]){

    int indiceClientes;
    for(indiceClientes=0; indiceClientes<tam_clientes; indiceClientes++) {
        auxClienteMascota[indiceClientes].idCliente = listaCliente[indiceClientes].idCliente;
        auxClienteMascota[indiceClientes].cantidadMascota = 0;
        }
//INICIALIZA EL LA ESTRUCTURA CLIENTES_MASCOTA
}

void contadorDeMascotaporClientes(eCliente listasClientes[], int tam_clientes, eMascotas listasMascotas[], int tam_Mascotas,Clientes_Mascota auxClienteMascota[]){
    int indiceClientes;
    int indiceMascotas;
    for(indiceClientes=0; indiceClientes<tam_clientes; indiceClientes++) {
        for(indiceMascotas=0; indiceMascotas<tam_Mascotas; indiceMascotas++) {
            if(listasMascotas[indiceMascotas].estado==OCUPADO && auxClienteMascota[indiceClientes].idCliente == listasMascotas[indiceMascotas].idDuenio) {
                    auxClienteMascota[indiceClientes].cantidadMascota++;
            }
        }
    }
//CONTADOR DE MASCOTA DE LA ESTRUCTURA CLIENTES_MASCOTA
}

void ordenarClientePorCantidadyNombre(eMascotas listamascotas[], int tam_Mascota, eCliente listaclientes[], int tam_clientes){

    int indice_I;
    int indice_J;
    Clientes_Mascota auxClienteMascota[tam_clientes];
    Clientes_Mascota auxiliar;
    eCliente auxiliarClientes;

    inicializarClientes_Mascotas(auxClienteMascota,tam_clientes,listaclientes);
    contadorDeMascotaporClientes(listaclientes,tam_clientes,listamascotas,tam_Mascota,auxClienteMascota);


        for(indice_I=0; indice_I<tam_clientes-1; indice_I++) {
            for(indice_J=indice_I+1; indice_J<tam_clientes; indice_J++) {
                if(auxClienteMascota[indice_I].cantidadMascota<auxClienteMascota[indice_J].cantidadMascota){
                    auxiliar = auxClienteMascota[indice_I];
                    auxClienteMascota[indice_I] = auxClienteMascota[indice_J];
                    auxClienteMascota[indice_J] = auxiliar;

                    auxiliarClientes = listaclientes[indice_I];
                    listaclientes[indice_I]= listaclientes[indice_J];
                    listaclientes[indice_J]= auxiliarClientes;

                }else if(auxClienteMascota[indice_I].cantidadMascota==auxClienteMascota[indice_J].cantidadMascota){
                    if((stricmp(listaclientes[indice_I].nombre,listaclientes[indice_J].nombre))>0){

                        auxiliar = auxClienteMascota[indice_I];
                        auxClienteMascota[indice_I] = auxClienteMascota[indice_J];
                        auxClienteMascota[indice_J] = auxiliar;

                        auxiliarClientes = listaclientes[indice_I];
                        listaclientes[indice_I]= listaclientes[indice_J];
                        listaclientes[indice_J]= auxiliarClientes;

                    }


                }
            }
        }
        printf("------ORDENADO POR CANTIDAD Y NOMBRE (A-Z)------\n");
        printf("------------------------------------------------\n");
        printf("---- NOMBRE DUENIO------CANTIDAD MASCOTAS-------\n");
        printf("------------------------------------------------\n");
        for(indice_I = 0; indice_I<tam_clientes; indice_I++){
            if(listaclientes[indice_I].estado ==OCUPADO){
                printf("%15s %15d\n",listaclientes[indice_I].nombre,auxClienteMascota[indice_I].cantidadMascota);
            }

        }
 system("pause");

}

void dueniosquetienenMascotasdelMismosexo(eCliente listaCliente[], int tam_cliente,eMascotas listaMascota[], int tam_mascota){

    int indiceCliente;
    int indiceMascota;

    printf("\n\nMASCOTAS MASCULINAS");
    for(indiceCliente=0;indiceCliente< tam_cliente; indiceCliente++){
        if(listaCliente[indiceCliente].estado==OCUPADO){
            for(indiceMascota=0;indiceMascota<tam_mascota;indiceMascota++){
                if(listaMascota[indiceMascota].estado==OCUPADO && listaMascota[indiceMascota].sexo=='M'){
                    printf("\n%s %c \n",listaCliente[indiceCliente].nombre, listaMascota[indiceMascota].sexo);
                    break;
                }
            }
        }
    }
    printf("\n\nMASCOTAS MASCULINAS");
    for(indiceCliente=0;indiceCliente< tam_cliente; indiceCliente++){
        if(listaCliente[indiceCliente].estado==OCUPADO){
            for(indiceMascota=0;indiceMascota<tam_mascota;indiceMascota++){
                if(listaMascota[indiceMascota].estado==OCUPADO && listaMascota[indiceMascota].sexo=='F'){
                    printf("\n%s %c \n",listaCliente[indiceCliente].nombre, listaMascota[indiceMascota].sexo);
                    break;
                }
            }
        }
    }
}


