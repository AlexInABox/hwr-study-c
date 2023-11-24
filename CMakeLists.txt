cmake_minimum_required(VERSION 3.26)
project(hwr_hello_world C)

set(CMAKE_C_STANDARD 11)

add_executable(E2T1 exercise_2/task_1.c)
add_executable(E2T2 exercise_2/task_2.c)
add_executable(E2T3 exercise_2/task_3.c)
add_executable(E2T4 exercise_2/task_4.c)
add_executable(E2T5 exercise_2/task_5.c)
add_executable(E2T6 exercise_2/task_6.c)
add_executable(E2T7 exercise_2/task_7.c)
add_executable(E2T8 exercise_2/task_8.c)

add_executable(E3T1 exercise_3/task_1.c)
add_executable(E3T2 exercise_3/task_2.c)
add_executable(E3T3 exercise_3/task_3.c)
add_executable(E3T4 exercise_3/task_4.c)
add_executable(E3T5 exercise_3/task_5.c)
add_executable(E3T6 exercise_3/task_6.c)
add_executable(E3T7 exercise_3/task_7.c)

#where is exercise 4... :(

add_executable(E5T1 exercise_5/task_1.c)
add_executable(E5T2 exercise_5/task_2.c)
add_executable(E5T3 exercise_5/task_3.c)
add_executable(E5T4 exercise_5/task_4.c)
add_executable(E5T5 exercise_5/task_5.c)


add_executable(inClass_pointer inClassStuff/pointer.c)
add_executable(inClass_spaceallocation inClassStuff/spaceallocation.c)
add_executable(inCall_queue inClassStuff/queue.c)



