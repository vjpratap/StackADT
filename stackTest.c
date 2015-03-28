#include "expr_assert.h"
#include <stdlib.h>
#include "stack.h"

void test_that_function_createStack_creates_the_stack_or_not(){
	Stack newStack = createStack();
	assert(newStack.list->count == 0);
	assert(*newStack.top == NULL);
}

void test_that_function_push_pushes_the_element_in_the_stack_or_not_for_int(){
	Stack newStack = createStack();
	int data = 2;
	assert(push(&newStack, &data)==1);
	assertEqual((*(int *)newStack.list->tail->data), 2);
}

void test_that_function_push_push_the_element_in_the_stack_for_float(){
	Stack newStack = createStack();
	float data = 2.83;
	assert(push(&newStack, &data)==1);
	assertEqual(*((float *)newStack.list->tail->data), 2.83);
}

void test_that_function_push_push_the_element_in_the_stack_for_char(){
	Stack newStack = createStack();
	char data = 'a';
	assert(push(&newStack, &data)==1);
	assertEqual((*(char *)newStack.list->tail->data), 'a');
}

void test_that_function_push_push_the_element_in_the_stack_for_string(){
	Stack newStack = createStack();
	char* data = "vijay";
	assert(push(&newStack, &data)==1);
	assertEqual((*(char**)newStack.list->tail->data), "vijay");
}

void test_that_function_push_increase_the_count_or_not(){
	Stack newStack = createStack();
	int data1 = 2, data2 = 4, data3 = 6;
	push(&newStack, &data1);
	push(&newStack, &data2);

	assert(push(&newStack, &data3) == 3);
	assertEqual(*(int *)newStack.list->head->data, 2);
	assertEqual(*(int *)*newStack.top, 6);
}

void test_that_function_pop_pops_the_element_in_the_stack_for_int(){
	Stack newStack = createStack();
	int data1 = 2, data2 = 4, data3 = 6;
	push(&newStack, &data1);
	push(&newStack, &data2);
	push(&newStack, &data3);
	assertEqual(newStack.list->count , 3);
	assertEqual(*(int *)pop(&newStack), 6);
	assertEqual(*(int *)newStack.list->tail->data, 4);	
	assertEqual(*(int *)newStack.list->head->data, 2);	
	assertEqual(newStack.list->count , 2);
}

void test_that_function_pop_pops_the_element_in_the_stack_for_char(){
	Stack newStack = createStack();
	char data1 = 'a', data2 = 'b', data3 = 'c';
	push(&newStack, &data1);
	push(&newStack, &data2);
	push(&newStack, &data3);
	assertEqual(newStack.list->count, 3);
	assertEqual(*(char *)pop(&newStack), 'c');
	assertEqual(*(char *)newStack.list->tail->data, 'b');	
	assertEqual(*(char *)newStack.list->head->data, 'a');	
	assertEqual(newStack.list->count , 2);
}

void test_that_function_pop_pops_the_element_in_the_stack_for_float(){
	Stack newStack = createStack();
	float data1 = 1.23, data2 = 3.54, data3 = 2.32;
	push(&newStack, &data1);
	push(&newStack, &data2);
	push(&newStack, &data3);
	assertEqual(newStack.list->count, 3);
	assertEqual(*(float *)pop(&newStack), 2.32);
	assertEqual(*(float *)newStack.list->tail->data, 3.54);	
	assertEqual(*(float *)newStack.list->head->data, 1.23);	
	assertEqual(newStack.list->count , 2);
}

void test_that_function_lifo_pops_the_first_element_in_the_stack_for_int(){
	Stack newStack = createStack();
	int data1 = 2, data2 = 4, data3 = 6;
	push(&newStack, &data1);
	push(&newStack, &data2);
	push(&newStack, &data3);
	assertEqual(newStack.list->count , 3);
	assertEqual(*(int *)lifo(&newStack), 2);
	assertEqual(*(int *)lifo(&newStack), 4);
	assertEqual(*(int *)lifo(&newStack), 6);
	// assertEqual(*(int *)newStack.list->tail->data, 6);	
	// assertEqual(*(int *)newStack.list->head->data, 4);	
	assertEqual(newStack.list->count , 0);
}

void test_that_function_lifo_pops_the_first_element_in_the_stack_for_char(){
	Stack newStack = createStack();
	char data1 = 'a', data2 = 'b', data3 = 'c';
	push(&newStack, &data1);
	push(&newStack, &data2);
	push(&newStack, &data3);
	assertEqual(newStack.list->count, 3);
	assertEqual(*(char *)lifo(&newStack), 'a');
	assertEqual(*(char *)newStack.list->tail->data, 'c');	
	assertEqual(*(char *)newStack.list->head->data, 'b');	
	assertEqual(newStack.list->count , 2);
}

void test_that_function_lifo_pops_the_first_element_in_the_stack_for_float(){
	Stack newStack = createStack();
	float data1 = 1.23, data2 = 3.54, data3 = 2.32;
	push(&newStack, &data1);
	push(&newStack, &data2);
	push(&newStack, &data3);
	assertEqual(newStack.list->count, 3);
	assertEqual(*(float *)lifo(&newStack), 1.23);
	assertEqual(*(float *)newStack.list->tail->data, 2.32);	
	assertEqual(*(float *)newStack.list->head->data, 3.54);	
	assertEqual(newStack.list->count , 2);
}

// void test_that_function_giveIndex_gives_the_index_of_element_in_the_stack_for_int(){
// 	Stack newStack = createStack();
// 	int data1 = 2, data2 = 4, data3 = 6;
// 	push(&newStack, &data1);
// 	push(&newStack, &data2);
// 	push(&newStack, &data3);
// 	assertEqual(newStack.list->count , 3);
// 	assertEqual(giveIndex(&newStack, &data3), 2	);
// 	assertEqual(giveIndex(&newStack, &data1), 0);	
// 	// assertEqual(*(int *)newStack.list->head->data, 4);	
// 	// assertEqual(newStack.list->count , 2);
// }

// void test_that_function_giveIndex_pops_the_first_element_in_the_stack_for_char(){
// 	Stack newStack = createStack();
// 	char data1 = 'a', data2 = 'b', data3 = 'c';
// 	push(&newStack, &data1);
// 	push(&newStack, &data2);
// 	push(&newStack, &data3);
// 	// assertEqual(newStack.list->count, 3);
// 	assertEqual(giveIndex(&newStack, &data2), 1);
// 	// assertEqual(*(char *)newStack.list->tail->data, 'c');	
// 	// assertEqual(*(char *)newStack.list->head->data, 'b');	
// 	// assertEqual(newStack.list->count , 2);
// }


