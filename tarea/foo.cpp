#include "foo.h"

Matriz2D::Matriz2D(){
    // Constructor por defecto
    this -> filas = 3;
    this -> columnas = 3;
    this -> ptr = new float*[filas];

    for(int i = 0; i <  filas; i ++){
        this -> ptr[i] = new float[columnas];

        for(int j = 0; j < columnas; j ++)
            this -> ptr[i][j] = (float) rand();
    }
}

Matriz2D::Matriz2D(int n){
    // Constructor con un parametro
    this -> filas = n;
    this -> columnas = n;
    this -> ptr = new float*[filas];

    for(int i = 0; i <  filas; i ++){
        this -> ptr[i] = new float[columnas];

        for(int j = 0; j < columnas; j ++)
            this -> ptr[i][j] = (float) rand();
    }
}

Matriz2D::Matriz2D(int n, int m){
    // Constructor con dos parametros
    this -> filas = n;
    this -> columnas = m;
    this -> ptr = new float*[filas];

    for(int i = 0; i <  filas; i ++){
        this -> ptr[i] = new float[columnas];

        for(int j = 0; j < columnas; j ++)
            this -> ptr[i][j] = (float) rand();
    }
}

Matriz2D::Matriz2D(const Matriz2D& m){
    // Constructor de copia
    this -> filas = m.filas;
    this -> columnas = m.columnas;
    this -> ptr = new float[filas];

    for(int i = 0; i <  filas; i ++){
        ptr[i] = new float[columnas];

        for(int j = 0; j < columnas; j ++)
            ptr[i][j] = m.ptr[i][j];
    }
}

Matriz2D::Matriz2D(Matriz2D&& m){
    // Constructor de movimiento
    this -> filas = m.filas;
    this -> columnas = m.columnas;
    ptr = m.ptr;
    d.ptr = nullptr;
}

Matriz2D t(Matriz2D& m){
    // Transpuesta de una matriz
    Matriz2D m_T(m.filas, m.columnas);

    for(int i = 0; i <  m.columnas; i ++){
        for(int j = 0; j < m.filas; j ++){
            m_T.ptr[i][j] = m.ptr[j][i]
        }
    }

    return m_T;
}

std::ostream& operator<<(std::ostream& os, const Matriz2D& m){
    // Sobrecarga del operador <<
    for(int i = 0; i <  m.columnas; i ++){
        for(int j = 0; j < m.filas; j ++)
            os << m.ptr[i][j] << " ";
        os << endl;
    }

    return os;
}

Matriz2D operator+(const Matriz2D& m1, const Matriz2D& m2){
    // Sobrecarga del operador +
    Matriz2D m_sum(m1.filas, m1.columnas);

    for(int i = 0; i <  m.filas; i ++){
        for(int j = 0; j < m.columnas; j ++){
            m_sum[i][j] = m1[i][j] + m2[i][j];
        }
    }
    
    return m_sum;
}

Matriz2D operator-(const Matriz2D& m1, const Matriz2D& m2){
    // Sobrecarga del operador -
    Matriz2D m_sub(m1.filas, m1.columnas);

    for(int i = 0; i <  m.filas; i ++){
        for(int j = 0; j < m.columnas; j ++){
            m_sub[i][j] = m1[i][j] - m2[i][j];
        }
    }

    return m_sub;
}

Matriz2D operator*(const Matriz2D& m1, const Matriz2D& m2){
    // Sobrecarga del operador *
    Matriz2D m_prod(m1.filas, m1.columnas);
    
    // for(int i = 0; i <  m.filas; i ++){
        
    //     for(int j = 0; j < m.columnas; j ++){
    //         m_prod[i][j] = 
    //     }
    // }

    return m_prod;
}

Matriz2D operator+(const Matriz2D& m, float n){
    // Sobrecarga del operador +
    Matriz2D m_sum(m1.filas, m1.columnas);

    for(int i = 0; i <  m.filas; i ++){
        for(int j = 0; j < m.columnas; j ++){
            m_sum[i][j] = m.ptr[i][j] + n;
        }
    }
    
    return m_sum;
}

Matriz2D operator-(const Matriz2D& m, float n){
    // Sobrecarga del operador -
    Matriz2D m_sub(m1.filas, m1.columnas);

    for(int i = 0; i <  m.filas; i ++){
        for(int j = 0; j < m.columnas; j ++){
            m_sub[i][j] = m.ptr[i][j] - n;
        }
    }
    
    return m_sub;
}

Matriz2D operator*(const Matriz2D& m, float n){
    // Sobrecarga del operador *
    Matriz2D m_prod(m1.filas, m1.columnas);

    for(int i = 0; i <  m.filas; i ++){
        for(int j = 0; j < m.columnas; j ++){
            m_prod[i][j] = m.ptr[i][j] * n;
        }
    }
    
    return m_prod;
}

Matriz2D operator/(const Matriz2D& m, float n){
    // Sobrecarga del operador /
    Matriz2D m_div(m1.filas, m1.columnas);

    for(int i = 0; i <  m.filas; i ++){
        for(int j = 0; j < m.columnas; j ++){
            m_div[i][j] = m.ptr[i][j] / n;
        }
    }
    
    return m_div;
}

float Matriz2D::get(int i, int j){
    return ptr[i][j];
}

int Matriz2D::getFilas(){
    return filas;
}

int Matriz2D::getColumnas(){
    return columnas;
}