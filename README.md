# Псеводрандомные генераторы

## Генератор ACORN (Additive Congruential Random Number)

### Введение

Генератор ACORN представляет собой алгоритм для генерации псевдослучайных чисел. Эти числа кажутся случайными, но на самом деле являются детерминированными и зависят от начальных условий. ACORN основан на концепции аддитивно-конгруэнтных генераторов, предоставляя простую математическую модель для создания последовательности случайных чисел.

### Математическое Определение

#### Параметры 

- **k (Порядок):** Конечное строго положительное целое число.
- **M (Модуль):** Конечное строго положительное целое число, представляющее модуль в операции по модулю.
- **$Y_{00}$ (Зерно):** Начальное строго положительное целое число, удовлетворяющее \(0 < Y\_{00} < M\).
- **$Y_{m0}$ (Начальные значения):** Список начальных значений для каждого \(m = 1, \ldots, k\).
- **n (Шаг генерации):** Целое положительное число, представляющее номер шага в генерации последовательности.

#### Уравнения 

1. \(Y_{0n} = Y_{0n-1}\) для \(n \geq 1\).
2. \(Y_{mn} = [Y_{m-1n} + Y\_{mn-1}] \mod M\) для \(n \geq 1, m = 1, \ldots, k\).

\[ Y = \begin{bmatrix} Y_{00} & Y_{10} & Y_{20} & \ldots & Y_{(k-1)0} \\ Y_{01} & Y_{11} & Y_{21} & \ldots & Y_{(k-1)1} \\ \vdots & \vdots & \vdots & \ddots & \vdots \\ Y_{0n} & Y_{1n} & Y_{2n} & \ldots & Y_{(k-1)n} \end{bmatrix} \]

Где каждый элемент $Y_{mn}$ вычисляется по формуле:
\[ Y_{mn} = \begin{cases} Y_{0(n-1)}, & \text{если } m = 0 \\ (Y_{(m-1)n} + Y_{mn-1}) \mod M, & \text{если } n \geq 1 \text{ и } m = 1, \ldots, k \end{cases} \]

### Инициализация

Генератор требует правильной инициализации для обеспечения хорошего качества случайных чисел. Рекомендации включают в себя выбор больших значений для \(M\), взаимно простых значений для \(Y_{00}\) и \(M\), а также выбор нечетного значения для \(Y_{00}\) при использовании \(M\) в виде степени двойки.

### Реализация

[Смотри код](https://github.com/pluttan/AOC/blob/main/pseudorandom/acorn/acorn.c)

## Blum Blum Shub

### Введение

### Blum Blum Инициализация

## Метод Фибоначчи с запаздываниями

### Введение

Запаздывающие генераторы Фибоначчи, также известные как аддитивные генераторы, являются генераторами псевдослучайных чисел. Они отличаются от генераторов, использующих линейный конгруэнтный алгоритм, и могут использоваться в статистических алгоритмах, требующих высокого разрешения.

### История

Последовательность Фибоначчи вида $X_{n+1} = (X_{n} + X_{n-1}) \mod (2^{m})$ зависит от более чем одного предшествующего значения. В начале 50-х годов этот алгоритм был изучен, но оказался неэффективным. В 1958 году была предложена доработанная формула:

$X_{n+1} = (X_{n} + X_{n-k}) \mod (2^{m})$

Эффективность достигалась при $k \geq 16$. В дальнейшем была выведена последовательность с запаздыванием:

$X_{n} = (X_{n-24} + X_{n-55}) \mod (2^{m})$

где $n \geq 55$, $m$ - чётное число, и $X_{0},X_{1},...,X_{54}$ - произвольные целые не все чётные числа.

Числа 24 и 55 называют запаздыванием, а числа $X_{n}$ определены как последовательность Фибоначчи с запаздыванием.

### Формула

Аддитивные генераторы генерируют случайные слова вместо случайных битов. Начальное состояние генератора - набор n-битовых слов: $X_{1},X_{2},...,X_{k}$.

Используется формула:

$X_{i} = (X_{i-a} + X_{i-b} + ... + X_{i-k}) \mod (2^{m})$

Период генератора должен быть не менее $2^{m}-1$.

### Реализация

Реализация написана с использованием первой формулы запаздывания: $X_{n} = (X_{n-24} + X_{n-55}) \mod (2^{m})$

[Смотри код](https://github.com/pluttan/AOC/blob/main/pseudorandom/fibonachi/fibonachi.c)

## Linear congruential generator

## Mersenne Twister
# Sort

## Bubble sort: for each pair of indices, swap the items if out of order

## Cocktail shaker sort or bidirectional bubble sort, a bubble sort traversing the list alternately from front to back and back to front

## Comb sort

## Gnome sort

## Odd–even sort

## Quicksort: divide list into two, with all items on the first list coming before all items on the second list.; then sort the two lists. Often the method of choice

## Bogosort

## Slowsort

## Stooge sort

## Flashsort

## Introsort: begin with quicksort and switch to heapsort when the recursion depth exceeds a certain level

## Timsort: adaptative algorithm derived from merge sort and insertion sort. Used in Python 2.3 and up, and Java SE 7.

## Insertion sort: determine where the current item belongs in the list of sorted ones, and insert it there

## Library sort

## Patience sorting

## Shell sort: an attempt to improve insertion sort

## Tree sort (binary tree sort): build binary tree, then traverse it to create sorted list

## Cycle sort: in-place with theoretically optimal number of writes

## Merge sort: sort the first and second half of the list separately, then merge the sorted lists

## Slowsort

## Strand sort

## Bead sort

## Bucket sort

## Burstsort: build a compact, cache efficient burst trie and then traverse it to create sorted output

## Counting sort

## Pigeonhole sort

## Postman sort: variant of Bucket sort which takes advantage of hierarchical structure

## Radix sort: sorts strings letter by letter

## Heapsort: convert the list into a heap, keep removing the largest element from the heap and adding it to the end of the list

## Selection sort: pick the smallest of the remaining elements, add it to the end of the sorted list

## Smoothsort

## Bitonic sorter

## Pancake sorting

## Spaghetti sort

## Topological sort

## Samplesort
