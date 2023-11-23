cmake_minimum_required(VERSION 3.26)
project(hwr_hello_world C)

set(CMAKE_C_STANDARD 11)

add_executable(exercise_1 exercise.c)
add_executable(exercise_2 exercise_2.c)
add_executable(exercise_3 exercise_3.c)
add_executable(E5T1 exercise_5/task_1.c)
add_executable(E5T2 exercise_5/task_2.c)
add_executable(E5T3 exercise_5/task_3.c)
add_executable(E5T4 exercise_5/task_4.c)
add_executable(E5T5 exercise_5/task_5.c)


add_executable(inClass_pointer inClassStudies/pointer.c)
add_executable(inClass_spaceallocation inClassStudies/spaceallocation.c)
add_executable(inCall_queue inClassStudies/queue.c)



