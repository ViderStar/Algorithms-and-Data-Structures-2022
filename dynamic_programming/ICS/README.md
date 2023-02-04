# **Задача 6. Строго возрастающая без разрывов подпоследовательность**
*Имя входного файла: input.txt <br/>
Имя выходного файла: output.txt <br/>
Ограничение по времени: 1 с <br/>
Ограничение по памяти: нет*

Необходимо из заданной числовой последовательности A, состоящей из n элементов, вычеркнуть минимальное число элементов так, чтобы оставшиеся элементы образовали строго возрастающую подпоследовательность элементов. Построенный алгоритм должен иметь трудоёмкость O(n log n).<br/>
*Замечание: возрастание без разрывов подразумевает, что каждый следующий элемент подпоследовательности строго больше предыдущего.*
## **Формат входных данных**
Первая строка входного файла содержит число n (1 ≤ n ≤ 700 000). Следующая строка содержит n элементов последовательности A, которые разделены пробелами (элементы последовательности — целые числа, не превосходящие по модулю 1 000 000 000).
## **Формат выходных данных**
Выведите одно число — длину строго возрастающей подпоследовательности элементов.
# **Примеры**
> input.txt :<br/>
6<br/>
1 2 3 4 7 6<br/>
output.txt :<br/>
>5