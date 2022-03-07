typedef struct TestResults {
	int mistakes;
	int correct;
} TestResults;

void display_test_results(char* tester_name, TestResults* test_results){
	if (test_results->mistakes == 0){
		fprintf(stdout, "\n\tAll tests in %s passed.\n"
						"\tThis does **NOT** mean your code is completely correct." 
						"\n\tThese are basic, sanity check tests and you should \n\tthoroughly" 
						" test your code to make sure it works."
						"\n\n"
						"\n\tThe numbers you see here are NOT representative of"
						"\n\tyour grade for this assignment."
						"\n\n", tester_name);
	} else {
		fprintf(stdout, "!---- 	SOME TESTS FAILED, SEE ABOVE FOR DETAILED OUTPUT ----!\n");
	}
}

void run_tests(char* tester_name, TestResults* (*test_fn)()){
	fprintf(stdout, "<<<... %s BEGIN\n\n", tester_name);
	TestResults* test_results = (*test_fn)();
	display_test_results(tester_name, test_results);
	free(test_results);
	fprintf(stdout, "END %s ...>>>\n\n", tester_name);
}
