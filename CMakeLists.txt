cmake_minimum_required(VERSION 3.26)
project(hwr_study_c C)

set(CMAKE_C_STANDARD 11)

find_package(PkgConfig REQUIRED) # ermöglicht das einfache Einbinden von Libraries
pkg_check_modules(GTK4 REQUIRED gtk4) # sucht das Paket gtk4 und erstellt die benötigten Variablen mit dem Prefix GTK4_ in den folgende Zeilen

include_directories(${GTK4_INCLUDE_DIRS})
link_directories(${GTK4_LIBRARY_DIRS})
add_definitions(${GTK4_CFLAGS_OTHER})

add_subdirectory(exercise_7/task_2_modules)

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

#why did exercise 6 vanish?.. ;(

add_executable(E7T1 exercise_7/task_1.c exercise_7/task_1_modules/palindrome.c)
add_executable(E7T2 exercise_7/task_2.c exercise_7/task_2_modules/voidStack.c)
add_executable(E7T3 exercise_7/task_3.c exercise_7/task_3_modules/geometry.c)

add_executable(E7T4 exercise_7/task_4.c)
target_link_libraries(E7T4 PUBLIC List) # Fügt die Library zur Applikation hinzu.
target_include_directories(E7T4 PUBLIC List) #Inkludiert die Headerdateien.
#add_executable(E7T4 exercise_7/task_4.c)
#add_executable(E7T5 exercise_7/task_5.c)



add_executable(inClass_pointer inClassStuff/pointer.c)
add_executable(inClass_spaceallocation inClassStuff/spaceallocation.c)
add_executable(inCall_queue inClassStuff/queue.c)

add_executable(E9T2 exercise_9/task_2.c)
target_link_libraries(E9T2 ${GTK4_LIBRARIES})

add_executable(E9T3 exercise_9/task_3.c)
target_link_libraries(E9T3 ${GTK4_LIBRARIES})

add_executable(E9T4 exercise_9/task_4.c)
target_link_libraries(E9T4 ${GTK4_LIBRARIES})

add_executable(E9T5 exercise_9/task_5.c)
target_link_libraries(E9T5 ${GTK4_LIBRARIES})

add_executable(E9T6 exercise_9/task_6.c)
target_link_libraries(E9T6 ${GTK4_LIBRARIES})

add_executable(E9T7 exercise_9/task_7.c)
target_link_libraries(E9T7 ${GTK4_LIBRARIES})

add_executable(MOCK_EXAM_ANCESTRY mock_exam/ancestry.c mock_exam/ancestry_modules/ancestry.c)
#add_executable(MOCK mock_exam/classBook.c)