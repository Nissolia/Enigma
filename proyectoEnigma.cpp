#include <iostream>
#include <windows.h>
#include <fstream>
/*********************************************/
/*         Proyecto de @Noelia Baños         */
/*********************************************/
using namespace std;
/*********************************************/
/*             C O N S T A N T E S           */
/*********************************************/
/* Constante de los puzzles totales */
const int MAX = 2;
const int VELOCIDAD = 10;
/*********************************/
/*         S T R U C T S         */
/*********************************/
struct problemas
{
    // poner los problemas a parte en la funcion de completando puzzles
    string pregunta, pista1, pista2, pista3, fallo, correcto;
};
/******************************************************/
/*        L L A M A D A   A   F U N C I O N E S       */
/******************************************************/
void borrarPantalla(int tiempo);
void textoLento(string texto, int tiempo);
void creandoPuzzles(problemas puzzles[]);
void historiaInicial();
void finalHistoria();
int pistasUsuario(problemas puzzles[], int elecc, int contador);
void primerosPasos(problemas puzzles[]);
void mostrarSegundoAcertijo(problemas puzzles[], int elecc);
void mostrarPrimerAcertijo(problemas puzzles[], int elecc);

/******************************/
/*          M A I N           */
/******************************/
int main()
{
    SetConsoleOutputCP(CP_UTF8); // Consola en español
    /* Variables que se usarán en el código*/
    problemas puzzles[MAX];
    /* Código ejecutable */
    creandoPuzzles(puzzles); // Funcion que llena el struct
    historiaInicial();
    primerosPasos(puzzles);
    borrarPantalla(500);
    textoLento("\n\nF I N", VELOCIDAD);
    /* Fin programa */
    return 0;
}

/****************************************************************/
/*                      F U N C I O N E S                       */
/****************************************************************/

/*****************************************************************************/
/*                           Función: Texto lento                            */
/*****************************************************************************/
/* Tener strings añade char a la cadena para poder imprimirlo por caracteres */
/* se hace dentro de un bucle para lograr este efecto                        */
/* se le da el tiempo para que se asimile a una persona escribiendo          */
/*   Entrada: string que se vovlera char y tiempo de "escritura "            */
/*   Salida: Ninguna                                                         */
/*****************************************************************************/
void textoLento(string texto, int tiempo)
{
    for (char caracter : texto)
    {
        cout << caracter;
        Sleep(tiempo);
    }
}
/***************************************************************/
/*                  Funcion: Limpiar terminal                  */
/***************************************************************/
/* Borra El contenido que hay en pantalla permite al usuario   */
/* que termine de leer antes de ir a la siguiente pantalla     */
/***************************************************************/
/*   Entrada: Tiempo de espera                                 */
/*   Salida: Ninguna                                           */
/***************************************************************/
void borrarPantalla(int tiempo)
{
    cout << "\n\n";
    Sleep(tiempo);   // Pone el programa a dormir durante un tiempo en milisegundos: 500 son 1 seg
    system("pause"); // Pausa hasta que pulses alguna tecla
    system("cls");   // Borra todo el contenido del terminal
}

/************************************************************************************/
/*                           Funcion: Completando puzzles                           */
/************************************************************************************/
/* Esta funcion la usamos para meter en los structs los datos que tenemos en el txt */
/* usamos esta forma para poder tratar los datos de una forma mucho                 */
/* más cómoda y así no sobrecargamos el codigo del programa                         */
/************************************************************************************/
/*    Entrada: El array que usaremos para  mover los datos                          */
/*    Salida: Ninguna                                                               */
/************************************************************************************/
void creandoPuzzles(problemas puzzles[])
{
    string texto;
    char caracter;
    ifstream archivo; // Leemos el archivo

    archivo.open("acertijosEnigma.txt");

    if (archivo.is_open())
    {

        for (int i = 0; i < MAX; i++)
        {
            // Este dato lo usaremos para que la persona no repita los puzzles que haya completado
            getline(archivo, texto);
            puzzles[i].pregunta = texto;
            getline(archivo, texto);
            puzzles[i].pista1 = texto;
            getline(archivo, texto);
            puzzles[i].pista2 = texto;
            getline(archivo, texto);
            puzzles[i].pista3 = texto;
            getline(archivo, texto);
            puzzles[i].fallo = texto;
            getline(archivo, texto);
            puzzles[i].correcto = texto;
        }
    }
    else
    {
        // Este mensaje sale si no mete la persona el txt que corresponde
        textoLento(" \nToma el archivador que necesitas para completar el misterio . . .", VELOCIDAD);
    }

    archivo.close(); // Cierra el archivo después de leerlo
}

/************************************************************************/
/*                Funcion: Inicio de la historia                        */
/************************************************************************/
/* Muestra os primeros parrafos de la historia                          */
/************************************************************************/
/*    Entrada: Ninguna                                                  */
/*    Salida: Ninguna                                                   */
/************************************************************************/
void historiaInicial()
{
    // Esta funcion esta completamente llena de texto
    borrarPantalla(500);
    textoLento("\n\nEn el tranquilo pueblo de Enigma, un pequeño pueblo donde la gente caminaba sin preocupaciones por aquellas estrechas callejuelas.", VELOCIDAD);
    textoLento("\nLos ataques a los rebaños de los ganaderos cercanos por coyotes eran comunes pero un robo o un asesinato", VELOCIDAD);
    textoLento("\nen los mas de 5000 años que tenía el pueblo nunca había sucedido.\n", VELOCIDAD);
    textoLento("\nPara un lugareño de Enigma este halo de felicidad y costumbrismo era lo normal, pero para una persona ajena a todo esto", VELOCIDAD);
    textoLento("\nse podría haber dado perfectamente cuenta del halo que rodeaba al pueblo de misterio y miedo.", VELOCIDAD);
    textoLento("\nA lo largo del día los lugareños vivían una vida feliz y sin preocupaciones pero al llegar la noche aquel", VELOCIDAD);
    textoLento("\npequeño poblado parecía un pueblo fantasma.\n\n", VELOCIDAD);
    textoLento("\nAhora que estás situado pequeño lector te contaré lo que sucederá a lo largo de tu viaje por aquellas pequeñas callejuelas y casas.", VELOCIDAD);
    borrarPantalla(500);
    textoLento("\n\nAl llegar a Enigma la gente se acerca a ti feliz y te acompaña hasta el hostal más famoso y único de aquellos lares.", VELOCIDAD);
    textoLento("\nÚnico por poseer calaveras en su fachada. Calaveras de distintos tipos, de distintas dimensiones y de distintas formas.", VELOCIDAD);
    textoLento("\nAlgunas rotas, otras con mandíbula y algunas sin ella.", VELOCIDAD);
    textoLento("\n\nNo te dejan pensar mucho ya que cuando te das cuenta te encuentras en la recepción de dicho hostal firmando en un gran y", VELOCIDAD);
    textoLento("\nmugroso libro de visitantes.", VELOCIDAD);
    textoLento("\n\nEl recepcionista mientras firmas te da la espalda momentáneamente para poder elegir una habitación.", VELOCIDAD);
    textoLento("\nPuedes ver que hay 9 trozos de madera colgando en un gran corcho pegado a la pared,", VELOCIDAD);
    textoLento("\nte parece extraño ya que desde fuera el hostal no es que sea muy grande pero prefieres", VELOCIDAD);
    textoLento("\nno hacerle caso a tus instintos de huir de aquel pueblo.", VELOCIDAD);
    borrarPantalla(500);
    textoLento("\n\nNecesitas investigar porque se fueron tus tatarabuelos de aquel pueblo. Todas las líneas de investigación", VELOCIDAD);
    textoLento("\nque has estudiado te llevan al mismo punto en el cual te encuentras ahora.", VELOCIDAD);
    textoLento("\n_______ __   _ _____  ______ _______ _______", VELOCIDAD);
    textoLento("\n|______ | \\  |   |   |  ____ |  |  | |_____|", VELOCIDAD);
    textoLento("\n|______ |  \\_| __|__ |_____| |  |  | |     |", VELOCIDAD);
    borrarPantalla(500);
    textoLento("\n\nNecesitas saber porque tu familia tiene la maldición de ver sombras donde no las hay.", VELOCIDAD);
    textoLento("\nNecesitas romper dicha maldición por tu bien mental.", VELOCIDAD);
    textoLento("\nEstás cansado así que omites todas las conversaciones y pides que te dejen dormir un poco en tu cama.", VELOCIDAD);
    textoLento("\n\nTe dejan marchar con reticencia. Al subir las escaleras notas que sólo hay 4 habitaciones y te parece extraño,", VELOCIDAD);
    textoLento("\n¿donde se podrán encontrar las habitaciones restantes?\n", VELOCIDAD);
    borrarPantalla(500);
    textoLento("\n\nPrefieres volver a callar a esa voz en tu cabeza que te grita por huir. Entras en tu pequeña habitación.", VELOCIDAD);
    textoLento("\nLa cama es gigantesca y ocupa casi toda la estancia, justo en la entrada a la derecha está la puerta del baño.", VELOCIDAD);
    textoLento("\nAvisas a tu pareja de que has llegado al pueblo, guardas tu móvil en el bolsillo y cierras la puerta.", VELOCIDAD);
    borrarPantalla(500);
    textoLento("\n\nDejas la maleta en la entrada y te tumbas en la cama para descansar un poco. No deseas dormir mucho ya que necesitas", VELOCIDAD);
    textoLento("\ninvestigar aquel pueblo, por lo que pones una alarma para dentro de una hora. Tu móvil está al 80 porciento", VELOCIDAD);

    textoLento("\nBloqueas el móvil, lo pones al lado de tu cabeza y te duermes en pocos minutos.", VELOCIDAD);
    textoLento("\npor lo que no necesitas cargarlo. El viaje en autobús te ha dejado dolorido y muy cansado.", VELOCIDAD);
    borrarPantalla(500);
    textoLento("\n\nUn grito inhumano te despierta. Miras por la ventana y ves que la luna ha salido.", VELOCIDAD);
    textoLento("\nTe cuestionas en qué momento el tiempo se esfumó y tu móvil decidió no despertarte de dicha siesta.", VELOCIDAD);
    textoLento("\n\nAgarras tu móvil pero al intentar encenderlo aparece en la pantalla el símbolo de la batería acabada.", VELOCIDAD);
    textoLento("\nTiene algo menos de un ochenta porciento y te parece extraño pero el grito inhumano vuelve a", VELOCIDAD);
    textoLento("\nrepetirse y te invade un ansia de saber que sucede en la habitación contigua a la tuya.", VELOCIDAD);
}

/*************************************************************************/
/*                      Funcion: Pistas del usuario                      */
/*************************************************************************/
/* Le enseña al usuario las pistas si ha fallado 3, 6 o 9 veces          */
/*************************************************************************/
/*    Entrada: El array con los datos de los puzzles                     */
/*    Salida: Ninguna                                                    */
/*************************************************************************/
int pistasUsuario(problemas puzzles[], int elecc, int contador)
{

    /* PISTAS PARA EL USUARIO POR FALLAR TANTO */
    if (contador == 2)
    {
        cout << "\n\n";
        textoLento(puzzles[elecc].pista1, VELOCIDAD);
    }
    else if (contador == 4)
    {
        cout << "\n\n";
        textoLento(puzzles[elecc].pista2, VELOCIDAD);
    }
    else if (contador == 6)
    {
        cout << "\n\n";
        textoLento(puzzles[elecc].pista3, VELOCIDAD);
    }
    else if (contador > 8)
    {
        cout << "\n\n";
        textoLento(puzzles[elecc].pista1, VELOCIDAD);
        cout << "\n\n";
        textoLento(puzzles[elecc].pista2, VELOCIDAD);
        cout << "\n\n";
        textoLento(puzzles[elecc].pista3, VELOCIDAD);
    }

    return contador;
}


/************************************************************************/
/*                Funcion: Final de la historia                         */
/************************************************************************/
/* Muestra os últimos parrafos de la historia                           */
/************************************************************************/
/*    Entrada: Ninguna                                                  */
/*    Salida: Ninguna                                                   */
/************************************************************************/
void finalHistoria()
{
    // Esta funcion esta completamente llena de texto
    borrarPantalla(500);
    textoLento("\nEl tic tac del reloj resuena en la habitación, marcando el tiempo que queda antes de que el", VELOCIDAD);
    textoLento("\nsolsticio de invierno arrastre la oscuridad eterna sobre el pueblo.", VELOCIDAD);
    textoLento("\n\nDejas caer la foto del árbol, sintiendo el peso de un destino incierto. La única certeza es que la búsqueda del árbol maldito", VELOCIDAD);
    textoLento("\nes tu única esperanza de romper la cadena mortífera. Las sombras de la habitación danzan en torno a ti", VELOCIDAD);
    textoLento("\nmientras te enfrentas a la dualidad de tu misión: descubrir el lugar del árbol antes de la salida del sol,", VELOCIDAD);
    textoLento("\nmientras te conviertes en la presa de un dios vengativo.", VELOCIDAD);
    borrarPantalla(500);
    textoLento("\n\nCONTINUARÁ . . .", VELOCIDAD);
}

/*************************************************************************/
/*                  Funcion: Mostrar primer acertijo                     */
/*************************************************************************/
/* Nos mostrará la pregunta por pantalla                                 */
/* y luego comprobará si el usuario ha dicho correctamente la respuesta  */
/*************************************************************************/
/*    Entrada: El array con los datos de los puzzles                     */
/*                 y la eleccion del acertijo                            */
/*    Salida: Ninguna                                                    */
/*************************************************************************/
void mostrarPrimerAcertijo(problemas puzzles[], int elecc)
{
    int respuesta;
    int contador = 0;
    borrarPantalla(500);
        textoLento("\n\nTe acercas lentamente al cuerpo y al agacharte te caes al suelo horrorizado. La víctima no tiene cara, está arrancada.", VELOCIDAD);
        textoLento("\nNunca en tus 30 años habías visto algo así ni siquiera en tu trabajo de forense.", VELOCIDAD);
        textoLento("\n\nCon lágrimas en los ojos acercas tus manos para intentar arrancar algo de ropa y taparle la cara, pero al hacer esto escuchas algo caer de su bolsillo.", VELOCIDAD);
        textoLento("\nEncuentras un papel doblado, está algo manchado de sangre pero decides desdoblarlo.", VELOCIDAD);
    do
    {
        /* Usamos esto para mostrar en pantalla el puzzle que tendrá que resolver la persona */
        
        textoLento("\n\n", VELOCIDAD);
        textoLento(puzzles[elecc].pregunta, VELOCIDAD);
        textoLento("\n\n1: Pareja | 2: Recepcionista | 3: Madre \t", VELOCIDAD);
        cin >> respuesta;
        borrarPantalla(500);

        if (respuesta == 1)
        {
            textoLento(puzzles[elecc].correcto, VELOCIDAD);
            elecc++;
            mostrarSegundoAcertijo(puzzles, elecc);
        }
        else
        {
            textoLento(puzzles[elecc].fallo, VELOCIDAD);
            mostrarPrimerAcertijo(puzzles, elecc);
            borrarPantalla(500);
            contador++; // Añadimos el contador para que la persona vea pistas si falla
            contador = pistasUsuario(puzzles, elecc, contador);
        }

    } while (respuesta != 1);
    /* OPCIONES DE QUE LA PERSONA ELIJA SALIR RAPIDAMENTE O VOLVER A ELEGIR UN LUGAR DE LA CASA*/
}

/*************************************************************************/
/*                  Funcion: Mostrar segundo acertijo                    */
/*************************************************************************/
/* Nos mostrará la pregunta por pantalla                                 */
/* y luego comprobará si el usuario ha dicho correctamente la respuesta  */
/*************************************************************************/
/*    Entrada: El array con los datos de los puzzles                     */
/*                 y la eleccion del acertijo                            */
/*    Salida: Ninguna                                                    */
/*************************************************************************/
void mostrarSegundoAcertijo(problemas puzzles[], int elecc)
{
    int respuesta;
    int contador = 0;
    do
    {
        /* Usamos esto para mostrar en pantalla el puzzle que tendrá que resolver la persona */
        borrarPantalla(500);

        textoLento("\n\n", VELOCIDAD);
        textoLento(puzzles[elecc].pregunta, VELOCIDAD);
        textoLento("\n\n1: Maldición | 2: Pacto | 3: Asesinato \t", VELOCIDAD);
        cin >> respuesta;
        borrarPantalla(500);

        if (respuesta == 2)
        {
            textoLento(puzzles[elecc].correcto, VELOCIDAD);
            finalHistoria();
        }
        else
        {
            textoLento(puzzles[elecc].fallo, VELOCIDAD);
            mostrarSegundoAcertijo(puzzles, elecc);
            borrarPantalla(500);
            contador++; // Añadimos el contador para que la persona vea pistas si falla
            contador = pistasUsuario(puzzles, elecc, contador);
        }

    } while (respuesta != 1);
}

/**************************************************************************/
/*                      Funcion: Elección del puzzle                      */
/**************************************************************************/
/* Usuario escribe que zona quiere explorar                               */
/* y también tiene la opcion de no investigar más                         */
/* Puede huir antes de indagar más sobre los misterios que le esperan     */
/**************************************************************************/
/*    Entrada: Array de los puzzles                                       */
/*    Salida: Ninguna                                                     */
/**************************************************************************/
void primerosPasos(problemas puzzles[])
{
    int numero;

    borrarPantalla(500);
    textoLento("\n\n¿Qué es lo que harás?", VELOCIDAD);
    textoLento("\n\t1: Investigar | 2: No investigar \t", VELOCIDAD);
    cin >> numero;
    borrarPantalla(500);
    if (numero == 1) // Se pone a investigar
    {
        textoLento("\n\nNo es de tu incumbencia pero necesitas saber que sucede, la vena chismosa te llama. Y si los vecinos saben algo sobre tu maldición.", VELOCIDAD);
        textoLento("\nTe levantas de la cama, agarras el cargador como arma defensiva por si acaso y te diriges a la puerta.", VELOCIDAD);
        borrarPantalla(500);

        textoLento("\nAbres lentamente la puerta para ver si hay alguien en el pasillo pero está todo oscuro. Sólo la luz de emergencia al final del pasillo ilumina la estancia.", VELOCIDAD);
        textoLento("\nNo hay moros por la costa así que con tu cargador en mano bien agarrado sales al pasillo cerrando la puerta detrás de ti.", VELOCIDAD);
        textoLento("\nLa luz se enciende al detectar movimiento y das un respingo. No te esperabas que aquel pueblucho tuviera una tecnología tan avanzada.", VELOCIDAD);
        textoLento("\nNo tienen internet pero si luz que se enciende al detectar el movimiento. Niegas lentamente con la cabeza y te diriges a la puerta de tus vecinos de hostal.", VELOCIDAD);
        borrarPantalla(500);
        textoLento("\nNotas que la puerta está un poco abierta. Estiras la mano para agarrar el pomo y cuando estás a punto de alcanzarlo notas una respiración en la nuca.", VELOCIDAD);
        /* HACEMOS QUE EL USUARIO ELIJA LO SIGUIENTE POR HACER */
        borrarPantalla(500);
        textoLento("\n\n¿Qué es lo que harás?", VELOCIDAD);
        textoLento("\n\t1: Seguir investigando | 2: Huir porque te invade el miedo \t", VELOCIDAD);
        cin >> numero;
        borrarPantalla(500);

        if (numero == 1) // Sigue investigando
        {
            textoLento("\nAbres la puerta lentamente y ante ti se encuentra un cuerpo con una silueta encima de ella.", VELOCIDAD);
            textoLento("\n\nVes como la cabeza de dicha silueta se gira rápidamente ante tí y huye por la ventana. Por primera vez notas la ventana abierta,", VELOCIDAD);
            textoLento("\nel frío que hace en aquel pueblo por la noche y que tienes a menos de un metro de distancia un cuerpo.", VELOCIDAD);
            textoLento("\n\nNecesitas saber que ha pasado, sabes que este asesinato tiene relación con tu maldición, algo dentro de ti lo dice.", VELOCIDAD);
            int elecc = 0;
            mostrarPrimerAcertijo(puzzles, 0);
        }
        else if (numero == 2) // Huye
        {

            textoLento("\nPor una vez en tu vida le haces caso a esa vocecita que hay en tu cabeza de huir y en menos de un minuto estas de vuelta en tu habitación", VELOCIDAD);
            textoLento("\nponiendo una silla tras la puerta para hacer palanca. Pasas la noche en vela pero no vuelves a escuchar ni oído nada más a lo largo de la noche.", VELOCIDAD);
            textoLento("\n\nA la mañana siguiente tal como escuchas a los gallos cantar coges tus cosas y te vas en busca del primer autobús que sale de vuelta a la ciudad.", VELOCIDAD);
        }
        else
        {
            /* USUARIO SE CONFUNDE Y NO PONE BIEN LOS DATOS */
            borrarPantalla(500);

            textoLento("\n\nEsribe bien a donde quieres ir. . .", VELOCIDAD);
            primerosPasos(puzzles);
        }
    }
    else if (numero == 2) // Se va
    {
        textoLento("\n\nDecides quedarte en la cama, no deseas problemas con nadie y tu investigación es más importante.", VELOCIDAD);
        textoLento("\nVuelves a meterte en la cama pero esta vez con el pijama puesto.", VELOCIDAD);
        textoLento("\nLa voz no se vuelve a escuchar más a lo largo de la noche.", VELOCIDAD);
    }
    else
    {
        /* USUARIO SE CONFUNDE Y NO PONE BIEN LOS DATOS */
        borrarPantalla(500);

        textoLento("\n\nEsribe bien a donde quieres ir. . .", VELOCIDAD);
        primerosPasos(puzzles);
    }
}
