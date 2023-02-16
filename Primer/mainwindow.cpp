#include "mainwindow.h"
#include "./ui_mainwindow.h"

//INICIO NEURONA
Neurona::Neurona() // Constructor de la clase Neurona, inicializamos los valores para cada objeto que se creará
{
    id = red = green = blue = -1;
    voltaje = 0.0;
    posicion_x = posicion_y = 0;
    siguiente = NULL;
}

Neurona::~Neurona() //Destructor de la clase Neurona
{

}

void Neurona::agregarDato(int newId, float newVoltaje, int newPosicion_x, int newPosicion_y, int newRed, int newGreen, int newBlue)
{
    id = newId;
    voltaje = newVoltaje;
    posicion_x = newPosicion_x;
    posicion_y = newPosicion_y;
    red = newRed;
    green = newGreen;
    blue = newBlue;
}

void Neurona::mostrarDatos() //Método que muestra los valores del objeto Neurona
{
    cout << "ID: " << id << "\nVoltaje: " << voltaje << "\nPosicion X: " << posicion_x << "\nPosicion Y: " << posicion_y << "\nRed: " << red << "\nGreen: " << green << "\nBlue: " << blue << endl;
}



//INICIO LISTA NEURONA

listaNeurona::listaNeurona()
{
    inicio = NULL;
}

listaNeurona::~listaNeurona()
{

}

bool listaNeurona::vacia()
{
    if(inicio == NULL)
        return true;
    return false;
}

void listaNeurona::agregar_inicio(int newId, float newVoltaje, int newPosicion_x, int newPosicion_y, int newRed, int newGreen, int newBlue)
{
    Neurona *temp = new Neurona();
    temp->agregarDato(newId, newVoltaje, newPosicion_x, newPosicion_y, newRed, newGreen, newBlue);
    if(vacia())
    {
      inicio = temp;
    }
    else
    {
        temp->siguiente = inicio;
        inicio = temp;
    }
    //delete temp;
}

void listaNeurona::agregar_final(int newId, float newVoltaje, int newPosicion_x, int newPosicion_y, int newRed, int newGreen, int newBlue)
{
    Neurona *temp = new Neurona();
    temp->agregarDato(newId, newVoltaje, newPosicion_x, newPosicion_y, newRed, newGreen, newBlue);
    if(vacia())
    {
      inicio = temp;
    }
    else if(inicio->siguiente == NULL)
    {
        inicio->siguiente = temp;
    }
    else
    {
        Neurona *iter;
        iter = inicio;
        while(iter->siguiente != NULL)
        {
            iter = iter->siguiente;
        }
        iter->siguiente = temp;
    }
}

void listaNeurona::mostrar()
{
    if(vacia())
    {
      cout << "NO HAY NEURONAS" << endl;
    }
    else if(inicio->siguiente == NULL)
    {
        inicio->mostrarDatos();
    }
    else
    {
        Neurona *iter;
        iter = inicio;
        while(iter->siguiente != NULL)
        {
            iter->mostrarDatos();
            iter = iter->siguiente;
        }
        iter->mostrarDatos();
    }
}
//FINAL DE LISTA

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

