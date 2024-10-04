import matplotlib.pyplot as plt
import os

# Función para leer los datos desde el archivo
def leer_datos(archivo):
    with open(archivo, 'r') as f:
        lineas = f.readlines()
        
    # Verificar que el archivo tenga suficientes líneas
    if len(lineas) < 5:
        raise ValueError(f"El archivo {archivo} no tiene suficientes datos.")
    
    # Extraer los datos de cada línea y convertirlos a enteros
    bubble_times = list(map(int, lineas[0].strip().split()))
    insertion_times = list(map(int, lineas[2].strip().split()))
    quick_times = list(map(int, lineas[4].strip().split()))
    selection_times = list(map(int, lineas[6].strip().split()))
    stl_times = list(map(int, lineas[8].strip().split()))

    return bubble_times, insertion_times, quick_times, selection_times, stl_times

# Función para graficar los tiempos de los algoritmos
def graficar_algoritmos(sizes, bubble, insertion, quick, selection, stl):
    plt.figure(figsize=(10, 6))

    plt.plot(sizes, bubble, label='Bubble Sort', marker='o')
    plt.plot(sizes, insertion, label='Insertion Sort', marker='o')
    plt.plot(sizes, quick, label='Quick Sort', marker='o')
    plt.plot(sizes, selection, label='Selection Sort', marker='o')
    plt.plot(sizes, stl, label='STL Sort', marker='o')

    plt.title('Comparación de Tiempos de Algoritmos de Ordenamiento')
    plt.xlabel('Tamaño del conjunto de datos')
    plt.ylabel('Tiempo (ms)')
    plt.legend()
    plt.grid(True)

    # Guardar la figura en lugar de mostrarla
    plt.savefig('./comparacion_tiempos_algoritmos.png')  # Puedes cambiar el nombre del archivo
    plt.close()  # Cierra la figura para liberar memoria

# Tamaños de los conjuntos de datos (de acuerdo a tu código)
sizes = [5000,  10000, 20000,
                          30000, 40000, 50000]

# Ruta al archivo de resultados
archivo = '/home/antony/dev/ie0217/Tareas/Tarea4/BenchMarks/data/resultados.txt'

# Verificar si el archivo existe antes de leerlo
if not os.path.exists(archivo):
    print(f"Archivo no encontrado: {archivo}")
else:
    print("Archivo encontrado, procediendo con la lectura.")
    
    # Leer los datos desde el archivo
    try:
        bubble_times, insertion_times, quick_times, selection_times, stl_times = leer_datos(archivo)

        # Asegurarse de que todos los tiempos leídos no están vacíos
        if len(bubble_times) < 10 or len(insertion_times) < 10 or len(quick_times) < 10 or len(selection_times) < 10 or len(stl_times) < 10:
            raise ValueError("Una o más listas de tiempos tienen menos de 10 elementos.")

        # Calcular los promedios de las 10 ejecuciones por tamaño
        def calcular_promedios(tiempos, num_runs):
            return [sum(tiempos[i:i + num_runs]) / num_runs for i in range(0, len(tiempos), num_runs)]

        num_runs = 10
        promedio_bubble = calcular_promedios(bubble_times, num_runs)
        promedio_insertion = calcular_promedios(insertion_times, num_runs)
        promedio_quick = calcular_promedios(quick_times, num_runs)
        promedio_selection = calcular_promedios(selection_times, num_runs)
        promedio_stl = calcular_promedios(stl_times, num_runs)

        # Graficar los resultados y guardar la figura
        graficar_algoritmos(sizes, promedio_bubble, promedio_insertion, promedio_quick, promedio_selection, promedio_stl)

    except Exception as e:
        print(f"Error al leer o procesar el archivo: {e}")
