## leetcode_tasks

###1. Two Sum

##### EN

_Desription:_

Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:

Given nums = `[2, 7, 11, 15]`, target = 9,

Because `nums[0] + nums[1] = 2 + 7 = 9`,
return `[0, 1]`.

##### RU

_Описание:_

Поиск 2-х элементов вектора, сумма которых равна значению target.

_Алгоритм:_
- создаем вектор res для хранения и возврата результатов. Массив состоит из 2 элементов, хранящих индексы значений, сумма которых равна target.
- создаем map для хранения промежуточных результатов
- проходим в цикле по каждому элементу вектора:
  - вычисляем значение элемента вектора (искомое значение), которое нужно найти для текущего элемента
  - проверяем есть ли искомое значение в map для промежуточных результатов:
     - если искомое значение уже есть, то записываем индекс искомого значения в первый элемент 
     вектора результатов, а индекс текущего значения исходного массива во второй элемент вектора
     и завершаем работу цикла.
     - если искомого значения не найдено, записываем текущее значение и индекс исходного вектора в 
     промежуточный map как  ключ и значение соответственно.


### 167. Two Sum II - Input array is sorted

##### EN

_Desription:_

Given an array of integers that is already sorted in ascending order, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2.

Note:

Your returned answers (both index1 and index2) are not zero-based.
You may assume that each input would have exactly one solution and you may not use the same element twice.
Example:

Input: numbers = `[2,7,11,15]`, target = 9
Output: `[1,2]`
Explanation: The sum of 2 and 7 is 9. Therefore index1 = 1, index2 = 2.

##### RU

_Описание:_

Поиск 2-х элементов вектора, сумма которых равна значению target. вектор отсортирован по возрастанию.

_Алгоритм:_

- создаем вектор res для хранения и возврата результатов. Массив состоит из 2 элементов, хранящих индексы значений, сумма которых равна target.
- проходим в цикле по каждому элементу вектора:
   - выполняем поиск (бинарный поиск) элемента значение которого равно "целевое значение" - "значение текущего элемента"
   - если элемент найден, то записываем индекс текущего элемента исходного вектора (+1) в первый элемент 
   вектора результатов, а индекс искомого значения исходного вектора (+1) во второй элемент вектора 
   и завершаем работу цикла.
   - если значение не найдено, переходим к следующему элементу исходного вектора.

