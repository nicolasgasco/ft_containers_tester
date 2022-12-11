#include "set_tests.hpp"
#include <vector>

extern std::string test_name;

void test_set_empty_ctor(long count){
	//print job name
	test_name = "-SET EMPTY CONSTRUCTION TEST-";
	print_test_name(count);

	//std working
	timer_start();
	for (int i = 0; i < count; ++i){
		std::set<std::string> p1;
	}
	double std_res = timer_stop();
	std::cout << "std result: " << std_res << " sec | " << std::flush;

	//ft working
	timer_start();
	for (int i = 0; i < count; ++i){
		ft::set<std::string> p2;
	}
	double ft_res = timer_stop();
	std::cout << "ft result: " << ft_res << " sec | " << std::flush;
	print_result(std_res, ft_res);
}

void test_set_insert_val(long count){
	//print job name
	test_name = "-SET INSERT VALUE TEST-";
	print_test_name(count);

	//init
    const size_t N = 42;
	srand(time(NULL));
	{
	//output test
	timer_start();
	long err_count = 0;
		std::set<std::string> v1;
		ft::set<std::string> v2;
		for (size_t i = 0; i < N * N; ++i){
			std::string fill = getNewId();
			v1.insert(fill);
			v2.insert(fill);

		if (!ft::equal(v1.begin(),v1.end(),v2.begin()))
			++err_count;
	}
	double comp_res = timer_stop();
    print_comp_res(err_count, comp_res);
	}

	//std working
	std::set<std::string> v1;
	timer_start();
	for (int i = 0; i < count; ++i){
        std::string fill = getNewId();
		v1.insert(fill);
	}
	double std_res = timer_stop();
	std::cout << "std result: " << std_res << " sec | " << std::flush;
	
	//ft working 
	ft::set<std::string> v2;
	timer_start();
	for (int i = 0; i < count; ++i){
        std::string fill = getNewId();
		v2.insert(fill);
	}
	double ft_res = timer_stop();
	std::cout << "ft result: " << ft_res << " sec | " << std::flush;
	print_result(std_res, ft_res);
}


void test_set_size_empty_max(long count) {
	//print job name
	test_name = "-SET SIZE EMPTY MAX TEST-";
	print_test_name(count);

	//init
    const size_t N = 42;
	srand(time(NULL));
	{ 
	//output test
	timer_start();
	long err_count = 0;
	for (int i = 0; i < count / 3; ++i){
	    size_t num = rand() % N;
	    std::set<std::string> v1;
	    ft::set<std::string> v2;
        for (size_t i = 0; i < num; ++i) {
            std::string fill = getNewId();
            v1.insert(fill);
            v2.insert(fill);
        }
		int std_res = v1.size();
		int ft_res = v2.size();
		if (std_res != ft_res)
			++err_count;
        std_res = v1.max_size();
        ft_res = v2.max_size();
        if (std_res != ft_res)
			++err_count;
		bool std_res_b = v1.empty();
		bool ft_res_b = v2.empty();
		if (std_res_b != ft_res_b)
			++err_count;
	}
	double comp_res = timer_stop();
    print_comp_res(err_count, comp_res);
	}
	//std working
	std::set<std::string> v1;
	timer_start();
	for (int i = 0; i < count * 100; ++i){
		v1.size();
		v1.max_size();
		v1.empty();
	}
	double std_res = timer_stop();
	std::cout << "std result: " << std_res << " sec | " << std::flush;
	
	//ft working 
	    ft::set<std::string> v2;
	timer_start();
	for (int i = 0; i < count * 100; ++i){
		v2.size();
		v2.max_size();
		v2.empty();
	}
	double ft_res = timer_stop();
	std::cout << "ft result: " << ft_res << " sec | " << std::flush;
	print_result(std_res, ft_res);
}

void test_set_copy_ctor(long count) {
	//print job name
	test_name = "-SET COPY CONSTRUCTOR TEST-";
	print_test_name(count);

	//init
    const size_t N = 42;
	srand(time(NULL));
	{
	//output test
	timer_start();
	long err_count = 0;
	for (int i = 0; i < count / 3; ++i) {
	    size_t num = rand() % N;
	    std::set<std::string> v1;
	    ft::set<std::string> v2;
        for (size_t i = 0; i < num; ++i) {
	        std::string fill = getNewId();
            v1.insert(fill);
            v2.insert(fill);
        }
		std::set<std::string> v1_r(v1);
		ft::set<std::string> v2_r(v2);
		int std_res = v1_r.size();
		int ft_res = v2_r.size();
		if (std_res != ft_res)
			++err_count;
		if (!ft::equal(v1_r.begin(),v1_r.end(),v2_r.begin()))
			++err_count;
	}
	double comp_res = timer_stop();
    print_comp_res(err_count, comp_res);
	}

	//std working
    size_t num = rand() % N;
	std::set<std::string> v1;
    for (size_t i = 0; i < num; ++i) {
	    std::string fill = getNewId();
        v1.insert(fill);
    }
	timer_start();
	for (int i = 0; i < count; ++i){
	    std::set<std::string> v1_r(v1);
 	}
	double std_res = timer_stop();
	std::cout << "std result: " << std_res << " sec | " << std::flush;
	
	//ft working
	ft::set<std::string> v2;
    for (size_t i = 0; i < num; ++i) {
	    std::string fill = getNewId();
        v2.insert(fill);
    }
	timer_start();
	for (int i = 0; i < count; ++i){
		ft::set<std::string> v2_r(v2);
	}
	double ft_res = timer_stop();
	std::cout << "ft result: " << ft_res << " sec | " << std::flush;
	print_result(std_res, ft_res);
}

void test_set_begin_end(long count) {
	//print job name
	test_name = "-SET BEGIN END ITERS TEST-";
	print_test_name(count);

	//init
    const size_t N = 42;
	srand(time(NULL));
	{
	//output test
	timer_start();
	long err_count = 0;
	for (int i = 0; i < count / 3; ++i) {
	    size_t num = rand() % N;
	    std::set<std::string> v1;
	    ft::set<std::string> v2;
        for (size_t i = 0; i < num; ++i) {
	        std::string fill = getNewId();
            v1.insert(fill);
            v2.insert(fill);
        }
		int std_res = v1.size();
		int ft_res = v2.size();
		if (std_res != ft_res)
			++err_count;
        if (!num) continue;
		std::set<std::string>::iterator it = v1.begin();
		ft::set<std::string>::iterator it_ft = v2.begin();
		if (*it != *it_ft) ++err_count;
        std::set<std::string>::const_iterator c_it = v1.begin();
		ft::set<std::string>::const_iterator c_it_ft = v2.begin();
		if (*c_it != *c_it_ft) ++err_count;
        std::set<std::string>::iterator eit = v1.end();
		ft::set<std::string>::iterator eit_ft = v2.end();
        if (*(--eit) != *(--eit_ft)) ++err_count;
        std::set<std::string>::const_iterator c_eit = v1.end();
		ft::set<std::string>::const_iterator c_eit_ft = v2.end();
        if (*(--c_eit) != *--(c_eit_ft)) ++err_count;
	}
	double comp_res = timer_stop();
    print_comp_res(err_count, comp_res);
	}

	//std working
    size_t num = rand() % N;
	std::set<std::string> v1;
    for (size_t i = 0; i < num; ++i) {
	    std::string fill = getNewId();
        v1.insert(fill);
    }
	timer_start();
	for (int i = 0; i < count; ++i){
	    v1.begin();
        v1.end();
	}
	double std_res = timer_stop();
	std::cout << "std result: " << std_res << " sec | " << std::flush;
	
	//ft working
	ft::set<std::string> v2;
    for (size_t i = 0; i < num; ++i) {
	    std::string fill = getNewId();
        v2.insert(fill);
    }
	timer_start();
	for (int i = 0; i < count; ++i){
		v2.begin();
        v2.end();
	}
	double ft_res = timer_stop();
	std::cout << "ft result: " << ft_res << " sec | " << std::flush;
	print_result(std_res, ft_res);
}

void test_set_rbegin_rend(long count) {
	//print job name
	test_name = "-SET RBEGIN REND ITERS TEST-";
	print_test_name(count);

	//init
    const size_t N = 42;
	srand(time(NULL));
	{
	//output test
	timer_start();
	long err_count = 0;
	for (int i = 0; i < count / 3; ++i) {
	    size_t num = rand() % N;
	    std::set<std::string> v1;
	    ft::set<std::string> v2;
        for (size_t i = 0; i < num; ++i) {
	        std::string fill = getNewId();
            v1.insert(fill);
            v2.insert(fill);
        }
		int std_res = v1.size();
		int ft_res = v2.size();
		if (std_res != ft_res)
			++err_count;
        if (!num) continue;
		std::set<std::string>::reverse_iterator it = v1.rbegin();
		ft::set<std::string>::reverse_iterator it_ft = v2.rbegin();
		if (*it != *it_ft) ++err_count;
        std::set<std::string>::const_reverse_iterator c_it = v1.rbegin();
		ft::set<std::string>::const_reverse_iterator c_it_ft = v2.rbegin();
		if (*c_it != *c_it_ft) ++err_count;
        std::set<std::string>::reverse_iterator eit = v1.rend();
		ft::set<std::string>::reverse_iterator eit_ft = v2.rend();
        if (*(--eit) != *(--eit_ft)) ++err_count;
        std::set<std::string>::const_reverse_iterator c_eit = v1.rend();
		ft::set<std::string>::const_reverse_iterator c_eit_ft = v2.rend();
        if (*(--c_eit) != *--(c_eit_ft)) ++err_count;
	}
	double comp_res = timer_stop();
    print_comp_res(err_count, comp_res);
	}

	//std working
    size_t num = rand() % N;
	std::set<std::string> v1;
    for (size_t i = 0; i < num; ++i) {
	    std::string fill = getNewId();
        v1.insert(fill);
    }
	timer_start();
	for (int i = 0; i < count; ++i){
	    v1.rbegin();
        v1.rend();
	}
	double std_res = timer_stop();
	std::cout << "std result: " << std_res << " sec | " << std::flush;
	
	//ft working
	ft::set<std::string> v2;
    for (size_t i = 0; i < num; ++i) {
	    std::string fill = getNewId();
        v2.insert(fill);
    }
	timer_start();
	for (int i = 0; i < count; ++i){
		v2.rbegin();
        v2.rend();
	}
	double ft_res = timer_stop();
	std::cout << "ft result: " << ft_res << " sec | " << std::flush;
	print_result(std_res, ft_res);
}

void test_set_assignment_op(long count) {
	//print job name
	test_name = "-SET ASSIGNMENT OPERATOR TEST-";
	print_test_name(count);

	//init
    const size_t N = 42;
	srand(time(NULL));
	{
	//output test
	timer_start();
	long err_count = 0;
	for (int i = 0; i < count / 3; ++i) {
	    size_t num = rand() % N;
	    std::set<std::string> v1;
	    ft::set<std::string> v2;
		std::set<std::string> v1_r;
		ft::set<std::string> v2_r;
        for (size_t i = 0; i < num; ++i) {
	        std::string fill = getNewId();
            v1.insert(fill);
            v2.insert(fill);
        }
        v1_r = v1;
        v2_r = v2;
		int std_res = v1_r.size();
		int ft_res = v2_r.size();
		if (std_res != ft_res)
			++err_count;
		if (!ft::equal(v1_r.begin(),v1_r.end(),v2_r.begin()))
			++err_count;
	}
	double comp_res = timer_stop();
    print_comp_res(err_count, comp_res);
	}

	//std working
    size_t num = rand() % N;
	std::set<std::string> v1;
	std::set<std::string> v1_r;
    for (size_t i = 0; i < num; ++i) {
	    std::string fill = getNewId();
        v1.insert(fill);
    }
	timer_start();
	for (int i = 0; i < count; ++i){
        v1_r = v1;
 	}
	double std_res = timer_stop();
	std::cout << "std result: " << std_res << " sec | " << std::flush;
	
	//ft working
	ft::set<std::string> v2;
	ft::set<std::string> v2_r;
    for (size_t i = 0; i < num; ++i) {
	    std::string fill = getNewId();
        v2.insert(fill);
    }
	timer_start();
	for (int i = 0; i < count; ++i){
        v2_r = v2;
	}
	double ft_res = timer_stop();
	std::cout << "ft result: " << ft_res << " sec | " << std::flush;
	print_result(std_res, ft_res);
}

void test_set_range_ctor(long count) {
	//print job name
	test_name = "-SET RANGE CTOR TEST-";
	print_test_name(count);

	//init
    const size_t N = 42;
	srand(time(NULL));
	{
	//output test
	timer_start();
	long err_count = 0;
	for (int i = 0; i < count / 3; ++i) {
	    size_t num = rand() % N;
	    std::set<std::string> v1;
	    ft::set<std::string> v2;

        for (size_t i = 0; i < num; ++i) {
	        std::string fill = getNewId();
            v1.insert(fill);
            v2.insert(fill);
        }
		std::set<std::string> v1_r(v1.begin(), v1.end());
		ft::set<std::string> v2_r(v2.begin(), v2.end());
		int std_res = v1_r.size();
		int ft_res = v2_r.size();
		if (std_res != ft_res)
			++err_count;
		if (!ft::equal(v1_r.begin(),v1_r.end(),v2_r.begin()))
			++err_count;
	}
	double comp_res = timer_stop();
    print_comp_res(err_count, comp_res);
	}

	//std working
    size_t num = rand() % N;
	std::set<std::string> v1;
    for (size_t i = 0; i < num; ++i) {
	    std::string fill = getNewId();
        v1.insert(fill);
    }
	timer_start();
	for (int i = 0; i < count; ++i){
		std::set<std::string> v1_r(v1.begin(), v1.end());
 	}
	double std_res = timer_stop();
	std::cout << "std result: " << std_res << " sec | " << std::flush;
	
	//ft working
	ft::set<std::string> v2;
    for (size_t i = 0; i < num; ++i) {
	    std::string fill = getNewId();
        v2.insert(fill);
    }
	timer_start();
	for (int i = 0; i < count; ++i){
		ft::set<std::string> v2_r(v2.begin(), v2.end());
	}
	double ft_res = timer_stop();
	std::cout << "ft result: " << ft_res << " sec | " << std::flush;
	print_result(std_res, ft_res);
}

void test_set_comparison(long count) {
	//print job name
	test_name = "-SET COMPARISON OPERATIONS TEST-";
	print_test_name(count);

	//init
    const size_t N = 42;
	srand(time(NULL));
	{
	//output test
	timer_start();
	long err_count = 0;
	for (int i = 0; i < count / 3; ++i) {
	    size_t num = rand() % N;
	    std::set<std::string> v1;
	    std::set<std::string> v1_r;
	    ft::set<std::string> v2;
	    ft::set<std::string> v2_r;

        for (size_t i = 0; i < num; ++i) {
	        std::string fill = getNewId();
            v1.insert(fill);
            v1_r.insert(fill);
            v2.insert(fill);
            v2_r.insert(fill);
        }
		if ((v1==v1_r) != (v2==v2_r)) ++err_count;
		if ((v1<v1_r) != (v2<v2_r)) ++err_count;
		if ((v1!=v1_r) != (v2!=v2_r)) ++err_count;
		if ((v1>v1_r) != (v2>v2_r)) ++err_count;
		if ((v1<=v1_r) != (v2<=v2_r)) ++err_count;
		if ((v1>=v1_r) != (v2>=v2_r)) ++err_count;
	}
	double comp_res = timer_stop();
    print_comp_res(err_count, comp_res);
	}
}

void test_set_find(long count) {
	//print job name
	test_name = "-SET FIND TEST-";
	print_test_name(count);

	//init
    const size_t N = 42;
	srand(time(NULL));
	{
	//output test
	timer_start();
	long err_count = 0;
	for (int i = 0; i < count / 3; ++i) {
	    size_t num = rand() % N;
	    std::set<std::string> v1;
	    ft::set<std::string> v2;
		std::string save_to_find;
        for (size_t i = 0; i < num; ++i) {
	        std::string fill = getNewId();
            v1.insert(fill);
            v2.insert(fill);
			save_to_find = fill;
        }
        std::string ref = getNewId();
		ptrdiff_t d1 = std::distance(v1.begin(), v1.find(ref));
		ptrdiff_t d2 = std::distance(v2.begin(), v2.find(ref));
        if (d1 != d2) ++err_count;
		d1 = std::distance(v1.begin(), v1.find(save_to_find));
		d2 = std::distance(v2.begin(), v2.find(save_to_find));
        if (d1 != d2) ++err_count;
	}
	double comp_res = timer_stop();
    print_comp_res(err_count, comp_res);
	}

	//std working
    size_t num = rand() % N;
	std::set<std::string> v1;
    std::string fill_s;
    for (size_t i = 0; i < num; ++i) {
	    fill_s = getNewId();
        v1.insert(fill_s);
    }
	timer_start();
	for (int i = 0; i < count; ++i){
		v1.find(fill_s);
	}
	double std_res = timer_stop();
	std::cout << "std result: " << std_res << " sec | " << std::flush;
	
	//ft working
	ft::set<std::string> v2;
    for (size_t i = 0; i < num; ++i) {
	    fill_s = getNewId();
        v2.insert(fill_s);
    }
	timer_start();
	for (int i = 0; i < count; ++i){
		v2.find(fill_s);
	}
	double ft_res = timer_stop();
	std::cout << "ft result: " << ft_res << " sec | " << std::flush;
	print_result(std_res, ft_res);
}

void test_set_swap(long count) {
	//print job name
	test_name = "-SET SWAP TEST-";
	print_test_name(count);

	//init
    const size_t N = 42;
	srand(time(NULL));
	{
	//output test
	timer_start();
	long err_count = 0;
	for (int i = 0; i < count / 6; ++i) {
	    size_t num = N;
	    std::set<std::string> v1;
	    ft::set<std::string> v2;
        for (size_t i = 0; i < num; ++i) {
	        std::string fill = getNewId();
            v1.insert(fill);
            v2.insert(fill);
        }
		std::set<std::string> v1_r(v1);
		ft::set<std::string> v2_r(v2);
		v1.swap(v1_r);
		v2.swap(v2_r);
		if (v1.size() != v1_r.size())
			++err_count;
		if (!ft::equal(v1_r.begin(),v1_r.end(),v2_r.begin()))
			++err_count;
		if (!ft::equal(v1.begin(),v1.end(),v2.begin()))
			++err_count;
	}
	double comp_res = timer_stop();
    print_comp_res(err_count, comp_res);
	}

	//std working
    size_t num = rand() % N;
	std::set<std::string> v1;
	std::set<std::string> v1_r;
    for (size_t i = 0; i < num; ++i) {
	    std::string fill = getNewId();
        v1.insert(fill);
        v1_r.insert(fill);
    }
	timer_start();
	for (int i = 0; i < count; ++i){
		v1.swap(v1_r);
	}
	double std_res = timer_stop();
	std::cout << "std result: " << std_res << " sec | " << std::flush;
	
	//ft working
	ft::set<std::string> v2;
	ft::set<std::string> v2_r;
    for (size_t i = 0; i < num; ++i) {
	    std::string fill = getNewId();
        v2.insert(fill);
        v2_r.insert(fill);
    }
	timer_start();
	for (int i = 0; i < count; ++i){
		v2.swap(v2_r);
	}
	double ft_res = timer_stop();
	std::cout << "ft result: " << ft_res << " sec | " << std::flush;
	print_result(std_res, ft_res);
}

void test_set_count_clear(long count) {
	//print job name
	test_name = "-SET COUNT CLEAR TEST-";
	print_test_name(count);

	//init
    const size_t N = 42;
	srand(time(NULL));
	{
	//output test
	timer_start();
	long err_count = 0;
	for (int i = 0; i < count / 3; ++i) {
	    size_t num = rand() % N;
	    std::set<std::string> v1;
	    ft::set<std::string> v2;
		std::string save_to_find;
        for (size_t i = 0; i < num; ++i) {
	        std::string fill = getNewId();
            v1.insert(fill);
            v2.insert(fill);
			save_to_find = fill;
        }
        std::string ref = getNewId();
		size_t d1 = v1.count(ref);
		size_t d2 = v2.count(ref);
        if (d1 != d2) ++err_count;
		d1 = v1.count(save_to_find);
		d2 = v2.count(save_to_find);
        if (d1 != d2) ++err_count;
		v1.clear();
		v2.clear();
		d1 = v1.count(save_to_find);
		d2 = v2.count(save_to_find);
        if (d1 != d2) ++err_count;	
	}

	double comp_res = timer_stop();
    print_comp_res(err_count, comp_res);
	}

	//std working
    size_t num = rand() % N;
	std::set<std::string> v1;
    std::string fill_s;
    for (size_t i = 0; i < num; ++i) {
	    fill_s = getNewId();
        v1.insert(fill_s);
    }
	timer_start();
	for (int i = 0; i < count; ++i){
		v1.count(fill_s);
		v1.clear();
	}
	double std_res = timer_stop();
	std::cout << "std result: " << std_res << " sec | " << std::flush;
	
	//ft working
	ft::set<std::string> v2;
    for (size_t i = 0; i < num; ++i) {
	    fill_s = getNewId();
        v2.insert(fill_s);
    }
	timer_start();
	for (int i = 0; i < count; ++i){
		v2.count(fill_s);
		v2.clear();
	}
	double ft_res = timer_stop();
	std::cout << "ft result: " << ft_res << " sec | " << std::flush;
	print_result(std_res, ft_res);
}

void test_set_insert_range(long count){
	//print job name
	test_name = "-SET INSERT RANGE TEST-";
	print_test_name(count);

	//init
    const size_t N = 42;
	srand(time(NULL));
	{
	//output test
	timer_start();
	long err_count = 0;
		std::set<std::string> v1;
		std::set<std::string> v1_r;
		ft::set<std::string> v2;
		ft::set<std::string> v2_r;
		for (size_t i = 0; i < N * N; ++i){
			std::string fill = getNewId();
			v1.insert(fill);
			v2.insert(fill);

		if (!ft::equal(v1_r.begin(),v1_r.end(),v2_r.begin()))
			++err_count;
	}
	double comp_res = timer_stop();
    print_comp_res(err_count, comp_res);
	}

	//std working
	std::set<std::string> v1;
	std::set<std::string> v1_r;
	for (int i = 0; i < count; ++i){
        std::string fill = getNewId();
		v1.insert(fill);
	}
	timer_start();
	v1_r.insert(v1.begin(), v1.end());
	double std_res = timer_stop();
	std::cout << "std result: " << std_res << " sec | " << std::flush;
	
	//ft working 
	ft::set<std::string> v2;
	ft::set<std::string> v2_r;
	for (int i = 0; i < count; ++i){
        std::string fill = getNewId();
		v2.insert(fill);
	}
	timer_start();
	v2_r.insert(v2.begin(), v2.end());
	double ft_res = timer_stop();
	std::cout << "ft result: " << ft_res << " sec | " << std::flush;
	print_result(std_res, ft_res);
}

void test_set_erase(long count) {
	//print job name
	test_name = "-SET ERASE TEST-";
	print_test_name(count);

	//init
    const size_t N = 42;
	srand(time(NULL));
	{
	//output test
	timer_start();
	long err_count = 0;
	for (int i = 0; i < count / 3; ++i) {
	    size_t num = rand() % N;
	    std::set<std::string> v1;
	    ft::set<std::string> v2;
        for (size_t i = 0; i < num; ++i) {
	        std::string fill = getNewId();
            v1.insert(fill);
            v2.insert(fill);
        }
		if (v1.size() != v2.size())  ++err_count;
		v1.erase(v1.begin(), v1.end());
		v2.erase(v2.begin(), v2.end());
		if(v1.empty() != v2.empty()) { 
		//	std::cout << v1.size() << " " << v2.size() << std::endl; 
			++err_count;
		}
		if (v1.size() != v2.size())  ++err_count;
	}
	double comp_res = timer_stop();
    print_comp_res(err_count, comp_res);
	}

	//std working
    size_t num = rand() % N;
	std::set<std::string> v1;
    for (size_t i = 0; i < num; ++i) {
	    std::string fill = getNewId();
        v1.insert(fill);
    }
	timer_start();
	for (int i = 0; i < count; ++i){
		v1.erase(v1.begin(), v1.end());
	}
	double std_res = timer_stop();
	std::cout << "std result: " << std_res << " sec | " << std::flush;
	
	//ft working
	ft::set<std::string> v2;
    for (size_t i = 0; i < num; ++i) {
	    std::string fill = getNewId();
        v2.insert(fill);
    }
	timer_start();
	for (int i = 0; i < count; ++i){
		v2.erase(v2.begin(), v2.end());
	}
	double ft_res = timer_stop();
	std::cout << "ft result: " << ft_res << " sec | " << std::flush;
	print_result(std_res, ft_res);
}

void test_set_erase_pos(long count) {
	//print job name
	test_name = "-SET ERASE POS TEST-";
	print_test_name(count);

	//init
    const size_t N = 42;
	srand(time(NULL));
	{
	//output test
	timer_start();
	long err_count = 0;
	for (int i = 0; i < count / 3; ++i) {
	    size_t num = rand() % N + 1;
	    std::set<std::string> v1;
	    ft::set<std::string> v2;
        for (size_t i = 0; i < num; ++i) {
	        std::string fill = getNewId();
            v1.insert(fill);
            v2.insert(fill);
        }
		if (v1.size() != v2.size())  ++err_count;
		v1.erase(v1.begin());
		v2.erase(v2.begin());
		if(v1.empty() != v2.empty()) ++err_count;
		if (v1.size() != v2.size())  ++err_count;
		if (!ft::equal(v1.begin(),v1.end(),v2.begin()))
			++err_count;
	}
	double comp_res = timer_stop();
    print_comp_res(err_count, comp_res);
	}

	//std working
    size_t num = count;
	std::set<std::string> v1;
    for (size_t i = 0; i < num; ++i) {
	    std::string fill = getNewId();
        v1.insert(fill);
    }
	timer_start();
	for (size_t i = 0; i < num; ++i){
		v1.erase(v1.begin());
	}
	double std_res = timer_stop();
	std::cout << "std result: " << std_res << " sec | " << std::flush;
	
	//ft working
	ft::set<std::string> v2;
    for (size_t i = 0; i < num; ++i) {
	    std::string fill = getNewId();
        v2.insert(fill);
    }
	timer_start();
	for (size_t i = 0; i < num; ++i){
		v2.erase(v2.begin());
	}
	double ft_res = timer_stop();
	std::cout << "ft result: " << ft_res << " sec | " << std::flush;
	print_result(std_res, ft_res);
}

void test_set_erase_val(long count) {
	//print job name
	test_name = "-SET ERASE VALUE TEST-";
	print_test_name(count);

	//init
    const size_t N = 42;
	srand(time(NULL));
	{
	//output test
	timer_start();
	long err_count = 0;
	for (int i = 0; i < count / 3; ++i) {
	    size_t num = rand() % N;
	    std::set<std::string> v1;	    
		ft::set<std::string> v2;
		std::vector<std::string> save;
        for (size_t i = 0; i < num; ++i) {
	        std::string fill = getNewId();
			save.push_back(fill);
            v1.insert(fill);
            v2.insert(fill);
        }
		if (v1.size() != v2.size())  ++err_count;
		
		for (size_t i = 0; i < save.size(); ++i) {
			// std::cout << "erase at " << i << std::endl;
			// std::cout << "value at i : " << save[i] << std::endl;
			v1.erase(save[i]);
			v2.erase(save[i]);
		}
		if(v1.empty() != v2.empty()) ++err_count;
		if (v1.size() != v2.size()) {++err_count;
		std::cout << "std size: " << v1.size() << " ft size : " << v2.size() << std::endl;
		}
	}
	double comp_res = timer_stop();
    print_comp_res(err_count, comp_res);
	}
}

void test_set_upper_bound(long count) {
	//print job name
	test_name = "-SET UPPER BOUND TEST-";
	print_test_name(count);

	//init
    const size_t N = 42;
	srand(time(NULL));
	{
	//output test
	timer_start();
	long err_count = 0;
	for (int i = 0; i < count / 3; ++i) {
	    size_t num = rand() % N;
	    std::set<std::string> v1;
	    ft::set<std::string> v2;
        for (size_t i = 0; i < num; ++i) {
	        std::string fill = getNewId();
            v1.insert(fill);
            v2.insert(fill);
        }
		int std_res = v1.size();
		int ft_res = v2.size();
		if (std_res != ft_res)
			++err_count;
        if (!num) continue;
		std::string bound = getNewId();
		std::set<std::string>::iterator it = v1.upper_bound(bound);
		ft::set<std::string>::iterator it_ft = v2.upper_bound(bound);
		if (it == v1.end() || it_ft == v2.end()) continue;
		if (*it != *it_ft) ++err_count;
	}
	double comp_res = timer_stop();
    print_comp_res(err_count, comp_res);
	}

	//std working
    size_t num = rand() % N;
	std::set<std::string> v1;
    for (size_t i = 0; i < num; ++i) {
	    std::string fill = getNewId();
        v1.insert(fill);
    }
	std::string bound = getNewId();
	timer_start();
	for (int i = 0; i < count; ++i){
		v1.upper_bound(bound);
	}
	double std_res = timer_stop();
	std::cout << "std result: " << std_res << " sec | " << std::flush;
	
	//ft working
	ft::set<std::string> v2;
    for (size_t i = 0; i < num; ++i) {
	    std::string fill = getNewId();
        v2.insert(fill);
    }
	timer_start();
	for (int i = 0; i < count; ++i){
		v2.upper_bound(bound);
	}
	double ft_res = timer_stop();
	std::cout << "ft result: " << ft_res << " sec | " << std::flush;
	print_result(std_res, ft_res);
}

void test_set_lower_bound(long count) {
	//print job name
	test_name = "-SET LOWER BOUND TEST-";
	print_test_name(count);

	//init
    const size_t N = 42;
	srand(time(NULL));
	{
	//output test
	timer_start();
	long err_count = 0;
	for (int i = 0; i < count / 3; ++i) {
	    size_t num = rand() % N;
	    std::set<std::string> v1;
	    ft::set<std::string> v2;
        for (size_t i = 0; i < num; ++i) {
	        std::string fill = getNewId();
            v1.insert(fill);
            v2.insert(fill);
        }
		int std_res = v1.size();
		int ft_res = v2.size();
		if (std_res != ft_res)
			++err_count;
        if (!num) continue;
		std::string bound = getNewId();
		std::set<std::string>::iterator it = v1.lower_bound(bound);
		ft::set<std::string>::iterator it_ft = v2.lower_bound(bound);
		if (it == v1.end() || it_ft == v2.end()) continue;
		if (*it != *it_ft) ++err_count;
	}
	double comp_res = timer_stop();
    print_comp_res(err_count, comp_res);
	}

	//std working
    size_t num = rand() % N;
	std::set<std::string> v1;
    for (size_t i = 0; i < num; ++i) {
	    std::string fill = getNewId();
        v1.insert(fill);
    }
	std::string bound = getNewId();
	timer_start();
	for (int i = 0; i < count; ++i){
		v1.lower_bound(bound);
	}
	double std_res = timer_stop();
	std::cout << "std result: " << std_res << " sec | " << std::flush;
	
	//ft working
	ft::set<std::string> v2;
    for (size_t i = 0; i < num; ++i) {
	    std::string fill = getNewId();
        v2.insert(fill);
    }
	timer_start();
	for (int i = 0; i < count; ++i){
		v2.lower_bound(bound);
	}
	double ft_res = timer_stop();
	std::cout << "ft result: " << ft_res << " sec | " << std::flush;
	print_result(std_res, ft_res);
}

void test_set_equal_range(long count) {
	//print job name
	test_name = "-SET EQUAL RANGE TEST-";
	print_test_name(count);

	//init
    const size_t N = 42;
	srand(time(NULL));
	{
	//output test
	timer_start();
	long err_count = 0;
	for (int i = 0; i < count / 3; ++i) {
	    size_t num = rand() % N;
	    std::set<std::string> v1;
	    ft::set<std::string> v2;
        for (size_t i = 0; i < num; ++i) {
	        std::string fill = getNewId();
            v1.insert(fill);
            v2.insert(fill);
        }
		int std_res = v1.size();
		int ft_res = v2.size();
		if (std_res != ft_res)
			++err_count;
        if (!num) continue;
		std::string bound = getNewId();
		std::pair<std::set<std::string>::iterator, 
			std::set<std::string>::iterator> it = v1.equal_range(bound);
		ft::pair<ft::set<std::string>::iterator, 
			ft::set<std::string>::iterator> it_ft = v2.equal_range(bound);
		if (it.first == v1.end() || it_ft.first == v2.end()) continue;
		if (*it.first != *it_ft.first) ++err_count;
	}
	double comp_res = timer_stop();
    print_comp_res(err_count, comp_res);
	}

	//std working
    size_t num = rand() % N;
	std::set<std::string> v1;
    for (size_t i = 0; i < num; ++i) {
	    std::string fill = getNewId();
        v1.insert(fill);
    }
	std::string bound = getNewId();
	timer_start();
	for (int i = 0; i < count; ++i){
		v1.equal_range(bound);
	}
	double std_res = timer_stop();
	std::cout << "std result: " << std_res << " sec | " << std::flush;
	
	//ft working
	ft::set<std::string> v2;
    for (size_t i = 0; i < num; ++i) {
	    std::string fill = getNewId();
        v2.insert(fill);
    }
	timer_start();
	for (int i = 0; i < count; ++i){
		v2.equal_range(bound);
	}
	double ft_res = timer_stop();
	std::cout << "ft result: " << ft_res << " sec | " << std::flush;
	print_result(std_res, ft_res);
}
