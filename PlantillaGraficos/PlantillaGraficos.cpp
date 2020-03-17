// PlantillaGraficos.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <stdio.h>
#include <stdlib.h>

#define GLEW_STATIC

#include "GL/glew.h"
#include "GLFW/glfw3.h"

#include <math.h>

#include <iostream>

#include "Shader.h"
#include "Vertice.h"
#include <vector>

using namespace std;

//Cada elemento que queramos renderear necesita 
//Un vertex array y un buffer
vector<Vertice> triangulo;
GLuint vertexArrayTrianguloID;
GLuint bufferTrianguloID;

vector<Vertice> cuadrado;
GLuint vertexArrayCuadradoID;
GLuint bufferCuadradoID;

//Instancia del shader
Shader *shader;
//Identificadores para mapeo de atributos de entrada
//del vertex shader
GLuint posicionID;
GLuint colorID;

void inicializarCuadrado() {

	//Pasto
	//Izquierda arriba
	Vertice v1 = {
		vec3(-1.0f,-0.5f,0.0f),
		vec4(0.0f,0.3f,0.1f,1.0f)
	};
	//Derecha arriba
	Vertice v2 = {
		vec3(1.0f,-0.5f,0.0f),
		vec4(0.0f,0.3f,0.1f,1.0f)
	};
	//Derecha abajo
	Vertice v3 = {
		vec3(1.0f,-1.0f,0.0f),
		vec4(0.0f,0.3f,0.1f,1.0f)
	};
	//Izquierda abajo
	Vertice v4 = {
		vec3(-1.0f,-1.0f,0.0f),
		vec4(0.0f,0.3f,0.1f,1.0f)
	};

	//Primer rectangulo
	Vertice v5 = {
		vec3(-0.9f,-0.7f,0.0f),
		vec4(0.4f,0.3f,0.1f,1.0f)
	};
	Vertice v6 = {
		vec3(0.9f,-0.7f,0.0f),
		vec4(0.4f,0.3f,0.1f,1.0f)
	};
	Vertice v7 = {
		vec3(0.9f,-0.9f,0.0f),
		vec4(0.4f,0.3f,0.1f,1.0f)
	};
	Vertice v8 = {
		vec3(-0.9f,-0.9f,0.0f),
		vec4(0.4f,0.3f,0.1f,1.0f)
	};

	//Segundo rectangulo
	Vertice v9 = {
		vec3(-0.7f,-0.5f,0.0f),
		vec4(0.4f,0.3f,0.1f,1.0f)
	};
	Vertice v10 = {
		vec3(0.7f,-0.5f,0.0f),
		vec4(0.4f,0.3f,0.1f,1.0f)
	};
	Vertice v11 = {
		vec3(0.9f,-0.9f,0.0f),
		vec4(0.4f,0.3f,0.1f,1.0f)
	};
	Vertice v12 = {
		vec3(-0.9f,-0.9f,0.0f),
		vec4(0.3f,0.3f,0.1f,1.0f)
	};

	//Tercer rectangulo
	Vertice v13 = {
		vec3(-0.5f,-0.3f,0.0f),
		vec4(0.4f,0.3f,0.1f,1.0f)
	};
	Vertice v14 = {
		vec3(0.5f,-0.3f,0.0f),
		vec4(0.4f,0.3f,0.1f,1.0f)
	};
	Vertice v15 = {
		vec3(0.9f,-0.9f,0.0f),
		vec4(0.4f,0.3f,0.1f,1.0f)
	};
	Vertice v16 = {
		vec3(-0.9f,-0.9f,0.0f),
		vec4(0.4f,0.3f,0.1f,1.0f)
	};

	//Cuarto rectangulo
	Vertice v17 = {
		vec3(-0.3f,-0.1f,0.0f),
		vec4(0.4f,0.3f,0.1f,1.0f)
	};
	Vertice v18 = {
		vec3(0.3f,-0.1f,0.0f),
		vec4(0.4f,0.3f,0.1f,1.0f)
	};
	Vertice v19 = {
		vec3(0.9f,-0.9f,0.0f),
		vec4(0.4f,0.3f,0.1f,1.0f)
	};
	Vertice v20 = {
		vec3(-0.9f,-0.9f,0.0f),
		vec4(0.4f,0.3f,0.1f,1.0f)
	};

	//Quinto rectangulo
	Vertice v21 = {
		vec3(-0.25f,0.1f,0.0f),
		vec4(0.4f,0.3f,0.1f,1.0f)
	};
	Vertice v22 = {
		vec3(0.25f,0.1f,0.0f),
		vec4(0.4f,0.3f,0.1f,1.0f)
	};
	Vertice v23 = {
		vec3(0.25f,-0.9f,0.0f),
		vec4(0.4f,0.3f,0.1f,1.0f)
	};
	Vertice v24 = {
		vec3(-0.25f,-0.9f,0.0f),
		vec4(0.4f,0.3f,0.1f,1.0f)
	};

	//Arboles
	Vertice v25 = {
		vec3(-1.0f,-0.1f,0.0f),
		vec4(0.4f,1.0f,0.3f,1.0f)
	};
	//Derecha arriba
	Vertice v26 = {
		vec3(1.0f,-0.1f,0.0f),
		vec4(0.4f,1.0f,0.3f,1.0f)
	};
	//Derecha abajo
	Vertice v27 = {
		vec3(1.0f,-0.5f,0.0f),
		vec4(0.4f,1.0f,0.3f,1.0f)
	};
	//Izquierda abajo
	Vertice v28 = {
		vec3(-1.0f,-0.5f,0.0f),
		vec4(0.4f,1.0f,0.3f,1.0f)
	};

	cuadrado.push_back(v1);
	cuadrado.push_back(v2);
	cuadrado.push_back(v3);
	cuadrado.push_back(v4);

	cuadrado.push_back(v25);
	cuadrado.push_back(v26);
	cuadrado.push_back(v27);
	cuadrado.push_back(v28);

	cuadrado.push_back(v5);
	cuadrado.push_back(v6);
	cuadrado.push_back(v7);
	cuadrado.push_back(v8);

	cuadrado.push_back(v9);
	cuadrado.push_back(v10);
	cuadrado.push_back(v11);
	cuadrado.push_back(v12);

	cuadrado.push_back(v13);
	cuadrado.push_back(v14);
	cuadrado.push_back(v15);
	cuadrado.push_back(v16);

	cuadrado.push_back(v17);
	cuadrado.push_back(v18);
	cuadrado.push_back(v19);
	cuadrado.push_back(v20);

	cuadrado.push_back(v21);
	cuadrado.push_back(v22);
	cuadrado.push_back(v23);
	cuadrado.push_back(v24);
}

void inicializarTriangulo() {
	Vertice v1 = {
		vec3(0.0f,0.3f,0.0f),
		vec4(0.8f,0.1f,0.0f,1.0f)
	};
	Vertice v2 = {
		vec3(-0.3f,-0.3f,0.0f),
		vec4(0.8f,0.1f,0.0f,1.0f)
	};
	Vertice v3 = {
		vec3(0.3f,-0.3f,0.0f),
		vec4(0.8f,0.1f,0.0f,1.0f)
	};
	triangulo.push_back(v1);
	triangulo.push_back(v2);
	triangulo.push_back(v3);
}

void dibujar() {
	//Elegir shader
	shader->enlazar();
	//Elegir el vertex array
	glBindVertexArray(vertexArrayTrianguloID);
	//Dibujar
	glDrawArrays(GL_TRIANGLES, 0, triangulo.size());

	//Proceso dibujo de Cuadrado
	glBindVertexArray(vertexArrayCuadradoID);
	glDrawArrays(GL_QUADS, 0, cuadrado.size());

	//Soltar vertex array
	glBindVertexArray(0);
	//Desenlazar shader
	shader->desenlazar();
}

int main()
{
    //Declarar una ventana
	GLFWwindow* window;

	//Si no se pudo iniciar GLFW
	//Terminamos ejecucion
	if (!glfwInit()) {
		exit(EXIT_FAILURE);
	}
	//Si se pudo iniciar GLFW
	//inicializamos la ventana
	window =
		glfwCreateWindow(600, 600, "Ventana",
			NULL, NULL);
	//Si no se pudo crear la venata
	//Terminamos ejecucion
	if (!window) {
		glfwTerminate();
		exit(EXIT_FAILURE);
	}
	//Establecemos la ventana como contexto
	glfwMakeContextCurrent(window);

	//Una vez establecido el contexto
	//Se activan las funciones "modernas" (gpu)
	glewExperimental = true;

	GLenum errores = glewInit();
	if (errores != GLEW_OK) {
		glewGetErrorString(errores);
	}

	const GLubyte* versionGL =
		glGetString(GL_VERSION);
	cout << "Version OpenGL: " << versionGL;

	//inicializarTriangulo();
	inicializarCuadrado();

	const char* rutaVertexShader =
		"VertexShader.shader";
	const char* rutaFragmentShader =
		"FragmentShader.shader";
	shader = new Shader(rutaVertexShader, rutaFragmentShader);

	//Mapeo de atributos
	posicionID =
		glGetAttribLocation(shader->getID(), "posicion");
	colorID =
		glGetAttribLocation(shader->getID(), "color");

	shader->desenlazar();

	//Crear el vertex array del triangulo
	glGenVertexArrays(1, &vertexArrayTrianguloID);
	glBindVertexArray(vertexArrayTrianguloID);
	//Vertex buffer
	glGenBuffers(1, &bufferTrianguloID);
	glBindBuffer(GL_ARRAY_BUFFER, bufferTrianguloID);
	//Asociar datos al buffer
	glBufferData(GL_ARRAY_BUFFER,
		sizeof(Vertice) * triangulo.size(),
		triangulo.data(), GL_STATIC_DRAW);
	//Habilitar atributos de shader
	glEnableVertexAttribArray(posicionID);
	glEnableVertexAttribArray(colorID);
	//Especificar a OpenGL como comunicarse
	glVertexAttribPointer(posicionID,
		3, GL_FLOAT, GL_FALSE,
		sizeof(Vertice), 0);
	glVertexAttribPointer(colorID,
		4, GL_FLOAT, GL_FALSE,
		sizeof(Vertice), (void*)sizeof(vec3));


	//Proceso de inicializar Vertex Array para el cuadrado
	glGenVertexArrays(1, &vertexArrayCuadradoID);
	glBindVertexArray(vertexArrayCuadradoID);
	glGenBuffers(1, &bufferCuadradoID);
	glBindBuffer(GL_ARRAY_BUFFER, bufferCuadradoID);
	glBufferData(GL_ARRAY_BUFFER,
		sizeof(Vertice) * cuadrado.size(),
		cuadrado.data(), GL_STATIC_DRAW);
	glEnableVertexAttribArray(posicionID);
	glEnableVertexAttribArray(colorID);
	glVertexAttribPointer(posicionID, 3, GL_FLOAT,
		GL_FALSE, sizeof(Vertice), 0);
	glVertexAttribPointer(colorID, 4, GL_FLOAT,
		GL_FALSE, sizeof(Vertice), (void*)sizeof(vec3));

	//Soltar el vertex array y el buffer
	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);





	//Ciclo de dibujo (Draw loop)
	while (!glfwWindowShouldClose(window)) {
		//Establecer region de dibujo
		glViewport(0, 0, 600, 600);
		//Establecemos el color de borrado
		//Valores RGBA
		glClearColor(0.0f, 0.8, 1.0f , 1.0f);
		//Borrar!
		glClear(GL_COLOR_BUFFER_BIT | 
			GL_DEPTH_BUFFER_BIT);

		//Actualizar valores y dibujar
		dibujar();

		glfwPollEvents();
		glfwSwapBuffers(window);
	}
	//Despúes del ciclo de dibujo
	//Eliminamos venta y procesos de glfw
	glfwDestroyWindow(window);
	glfwTerminate();
}
