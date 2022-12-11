#include "utility_tests.hpp"

extern std::string test_name;

void test_enableif_integral(long count){
	//print job name
	test_name = "-ENABLE IF IS INTEGRAL TEST-";
	print_test_name(count);

	//std working
	timer_start();
	for (int i = 0; i < count; ++i){
		is_odd(i);
	}
	double std_res = timer_stop();
	std::cout << "std result: " << std_res << " sec | " << std::flush;

	//ft working
	timer_start();
	for (int i = 0; i < count; ++i){
		is_odd_ft(i);
	}
	double ft_res = timer_stop();
	std::cout << "ft result: " << ft_res << " sec | " << std::flush;
	print_result(std_res, ft_res);
}

void test_equal_with_pred(long count){
	//print job name
	test_name = "-EQUAL TEST WITH PRED-";
	print_test_name(count);

	//init
	std::vector<int> v1;
	v1.push_back(42);
	v1.push_back(21);
	v1.push_back(4);
	v1.push_back(10);
	v1.push_back(12);
	v1.push_back(55);
	v1.push_back(25);
	v1.push_back(21);
	v1.push_back(42);
	std::vector<int> v2 (v1.begin(), v1.end());

	//output test
	timer_start();
	long err_count = 0;
	for (int i = 0; i < count / 10; ++i){
		std::random_shuffle(v1.begin(), v1.end());
		std::random_shuffle(v2.begin(), v2.end());
		bool std_res = ft::equal(v1.begin(), v1.end(),
                                  v2.begin(), ft_is_first_greater);
		bool ft_res = ft::equal(v1.begin(), v1.end(),
                                v2.begin(), ft_is_first_greater);
		if (std_res != ft_res)
			++err_count;
	}
	double comp_res = timer_stop();
    print_comp_res(err_count, comp_res);

	//std working
	timer_start();
	for (int i = 0; i < count; ++i){
		ft::equal(v1.begin(), v1.end(),
                   v2.begin(), ft_is_first_greater);
	}
	double std_res = timer_stop();
	std::cout << "std result: " << std_res << " sec | " << std::flush;
	
	//ft working 
	timer_start();
	for (int i = 0; i < count; ++i){
		ft::equal(v1.begin(), v1.end(),
                  v2.begin(), ft_is_first_greater);
	}
	double ft_res = timer_stop();
	std::cout << "ft result: " << ft_res << " sec | " << std::flush;
	print_result(std_res, ft_res);
}

void test_equal(long count){
	//print job name
	test_name = "-EQUAL TEST-";
	print_test_name(count);

	//init
	std::vector<int> v1;
	v1.push_back(42);
	v1.push_back(21);
	v1.push_back(4);
	v1.push_back(10);
	v1.push_back(12);
	v1.push_back(55);
	v1.push_back(25);
	v1.push_back(21);
	v1.push_back(42);
	std::vector<int> v2 (v1.begin(), v1.end());

	//output test
	timer_start();
	long err_count = 0;
	for (int i = 0; i < count / 10; ++i){
		std::random_shuffle(v1.begin(), v1.end());
		std::random_shuffle(v2.begin(), v2.end());
		bool std_res = ft::equal(v1.begin(), v1.end(),
                                  v2.begin());
		bool ft_res = ft::equal(v1.begin(), v1.end(),
                                v2.begin());
		if (std_res != ft_res)
			++err_count;
	}
	double comp_res = timer_stop();
    print_comp_res(err_count, comp_res);

	//std working
	timer_start();
	for (int i = 0; i < count; ++i){
		ft::equal(v1.begin(), v1.end(),
                   v2.begin());
	}
	double std_res = timer_stop();
	std::cout << "std result: " << std_res << " sec | " << std::flush;
	
	//ft working 
	timer_start();
	for (int i = 0; i < count; ++i){
		ft::equal(v1.begin(), v1.end(),
                  v2.begin());
	}
	double ft_res = timer_stop();
	std::cout << "ft result: " << ft_res << " sec | " << std::flush;
	print_result(std_res, ft_res);
}

void test_lexicographical_compare(long count){
	//print job name
	test_name = "-LEXIOGRAPHICAL COMPARE TEST-";
	print_test_name(count);

	//init
	std::vector<char> v1;
	v1.push_back('a');
	v1.push_back('b');
	v1.push_back('c');
	v1.push_back('d');
	v1.push_back('e');
	v1.push_back('f');
	v1.push_back('g');
	v1.push_back('h');
	v1.push_back('i');
	std::vector<char> v2 (v1.begin(), v1.end());

	//output test
	timer_start();
	long err_count = 0;
	for (int i = 0; i < count / 10; ++i){
		std::random_shuffle(v1.begin(), v1.end());
		std::random_shuffle(v2.begin(), v2.end());
		bool std_res = std::lexicographical_compare(v1.begin(), v1.end(),
                                    				v2.begin(), v2.end());
		bool ft_res = ft::lexicographical_compare(v1.begin(), v1.end(),
                                    			  v2.begin(), v2.end());
		if (std_res != ft_res)
			++err_count;
	}
	double comp_res = timer_stop();
    print_comp_res(err_count, comp_res);

	//std working
	timer_start();
	for (int i = 0; i < count; ++i){
		std::lexicographical_compare(v1.begin(), v1.end(),
                                    v2.begin(), v2.end());
	}
	double std_res = timer_stop();
	std::cout << "std result: " << std_res << " sec | " << std::flush;
	
	//ft working 
	timer_start();
	for (int i = 0; i < count; ++i){
		ft::lexicographical_compare(v1.begin(), v1.end(),
                                    v2.begin(), v2.end());
	}
	double ft_res = timer_stop();
	std::cout << "ft result: " << ft_res << " sec | " << std::flush;
	print_result(std_res, ft_res);
}

void test_lexicographical_compare_with_cmp(long count){
	//print job name
	test_name = "-LEXIOGRAPHICAL COMPARE WITH CMP-";
	print_test_name(count);

	//init
	std::vector<std::string> v1;
	v1.push_back("This");
	v1.push_back("Is");
	v1.push_back("A");
	v1.push_back("Bunch");
	v1.push_back("Of");
	v1.push_back("Test");
	v1.push_back("Strings");
	v1.push_back("To");
	v1.push_back("Compare");
	std::vector<std::string> v2 (v1.begin(), v1.end());

	//output test
	timer_start();
	long err_count = 0;
	for (int i = 0; i < count / 10; ++i){
		std::random_shuffle(v1.begin(), v1.end());
		std::random_shuffle(v2.begin(), v2.end());
		bool std_res = std::lexicographical_compare(v1.begin(), v1.end(),
                                    				v2.begin(), v2.end(), ft_comp);
		bool ft_res = ft::lexicographical_compare(v1.begin(), v1.end(),
                                    			  v2.begin(), v2.end(), ft_comp);
		if (std_res != ft_res)
			++err_count;
	}
	double comp_res = timer_stop();
    print_comp_res(err_count, comp_res);

	//std working
	timer_start();
	for (int i = 0; i < count; ++i){
		std::lexicographical_compare(v1.begin(), v1.end(),
                                    v2.begin(), v2.end(), ft_comp);
	}
	double std_res = timer_stop();
	std::cout << "std result: " << std_res << " sec | " << std::flush;
	
	//ft working 
	timer_start();
	for (int i = 0; i < count; ++i){
		ft::lexicographical_compare(v1.begin(), v1.end(),
                                    v2.begin(), v2.end(), ft_comp);
	}
	double ft_res = timer_stop();
	std::cout << "ft result: " << ft_res << " sec | " << std::flush;
	print_result(std_res, ft_res);
}

void test_pair_construction(long count){
	//print job name
	test_name = "-PAIR CONSTRUCTION TEST-";
	print_test_name(count);

	//std working
	timer_start();
	for (int i = 0; i < count; ++i){
		std::pair<int, int> p1(42, 42);
		std::pair<int, int> p2;
		p2 = p1;
	}
	double std_res = timer_stop();
	std::cout << "std result: " << std_res << " sec | " << std::flush;

	//ft working
	timer_start();
	for (int i = 0; i < count; ++i){
		ft::pair<int, int> p1(42, 42);
		ft::pair<int, int> p2;
		p2 = p1;
	}
	double ft_res = timer_stop();
	std::cout << "ft result: " << ft_res << " sec | " << std::flush;
	print_result(std_res, ft_res);
}

void test_pair_type_change(long count){
	//print job name
	test_name = "-PAIR TYPE CHANGE TEST-";
	print_test_name(count);

	//std working
	timer_start();
	for (int i = 0; i < count; ++i){
		std::pair<char, int> p1('s', 42);
		std::pair<int, double> p2;
		p2 = p1;
	}
	double std_res = timer_stop();
	std::cout << "std result: " << std_res << " sec | " << std::flush;

	//ft working
	timer_start();
	for (int i = 0; i < count; ++i){
		ft::pair<char, int> p1('s', 42);
		ft::pair<int, double> p2;
		p2 = p1;
	}
	double ft_res = timer_stop();
	std::cout << "ft result: " << ft_res << " sec | " << std::flush;
	print_result(std_res, ft_res);
}

void test_pair_make_pair(long count){
	//print job name
	test_name = "-PAIR MAKE PAIR TEST-";
	print_test_name(count);

	//std working
	timer_start();
	for (int i = 0; i < count; ++i){
		std::pair<char, int> p1 = std::make_pair ('c', 42);
		(void) p1;
	}
	double std_res = timer_stop();
	std::cout << "std result: " << std_res << " sec | " << std::flush;

	//ft working
	timer_start();
	for (int i = 0; i < count; ++i){
		ft::pair<char, int> p1 = ft::make_pair ('c', 42);
		(void) p1;
	}
	double ft_res = timer_stop();
	std::cout << "ft result: " << ft_res << " sec | " << std::flush;
	print_result(std_res, ft_res);
}

void test_pair_comparisons(long count){
	//print job name
	test_name = "-PAIR COMPARISONS TEST-";
	print_test_name(count);

	//std working
	timer_start();
	for (int i = 0; i < count; ++i){
		std::pair<char, int> p1 = std::make_pair ('c', 42);
		std::pair<char, int> p2 = std::make_pair ('c', 21);
		bool res;
		res = (p1 == p2);
		res = (p1 != p2);
		res = (p1 < p2);
		res = (p1 <= p2);
		res = (p1 > p2);
		res = (p1 >= p2);
		(void) res;
	}
	double std_res = timer_stop();
	std::cout << "std result: " << std_res << " sec | " << std::flush;

	//ft working
	timer_start();
	for (int i = 0; i < count; ++i){
		ft::pair<char, int> p1 = ft::make_pair ('c', 42);
		ft::pair<char, int> p2 = ft::make_pair ('c', 21);
		bool res;
		res = (p1 == p2);
		res = (p1 != p2);
		res = (p1 < p2);
		res = (p1 <= p2);
		res = (p1 > p2);
		res = (p1 >= p2);
		(void) res;
	}
	double ft_res = timer_stop();
	std::cout << "ft result: " << ft_res << " sec | " << std::flush;
	print_result(std_res, ft_res);
}
