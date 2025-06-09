# 📦 Proyecto de Simulación Logística Tipo Amazon

Este proyecto simula el proceso de recolección, empaquetado y entrega de productos desde un almacén automatizado, inspirado en el modelo logístico de Amazon. Está implementado completamente en C++ y utiliza algoritmos clásicos como **mochila 0/1**, **búsqueda BFS** y **Dijkstra**.

---

## 🧠 Objetivo

Desarrollar un sistema inteligente que:
- Recolecte productos en un almacén esquivando obstáculos
- Empaquete los productos óptimos según peso y volumen
- Determine rutas de entrega mínimas desde un centro logístico

---

## 🚀 Estructura del Proyecto

```
amazon_logistica_cpp/
├── data/             # Archivos de entrada
│   ├── mapa_almacen.txt
│   ├── productos.csv
│   ├── rutas.txt
│   └── pedidos.csv
├── includes/         # Headers (.hpp)
├── src/              # Implementaciones (.cpp)
├── tests/            # Pruebas unitarias
├── main.cpp          # Lógica principal por pedido
├── Makefile          # Compilación
```

---

## ⚙️ Tecnologías y Algoritmos Usados

- Lenguaje: **C++**
- Algoritmo mochila 0/1 con doble restricción (peso, volumen)
- Búsqueda BFS para generar rutas en el almacén
- Dijkstra para calcular rutas de entrega óptimas
- Simulación visual por consola con animación paso a paso

---

## 📦 Entradas del sistema

- `mapa_almacen.txt`: matriz 20x20 con S, P, # y .
- `productos.csv`: lista de productos con id, peso, volumen, valor
- `rutas.txt`: matriz de adyacencia del grafo de ciudades
- `pedidos.csv`: productos solicitados por pedido

---

## 💻 Cómo ejecutar

```bash
make run
```

Compila el sistema y ejecuta todos los pedidos.

---

## 🧪 Pruebas

Pruebas unitarias están ubicadas en la carpeta `/tests`:

```bash
g++ -Iincludes src/utils.cpp tests/test_pedidos.cpp -o test_pedidos
./test_pedidos
```

---

## 🎯 Ejemplo de animación

```
Paso 33/33
S * * * * * * * P . . . # . . . P . . .
. # # . . . # . . # . . . # . . . . # .
...
```

---

## 👨‍💻 Autores

- Daniel Sanchez
