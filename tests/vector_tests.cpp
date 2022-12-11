#include "vector_tests.hpp"

extern std::string test_name;

void test_vector_empty_ctor(long count){
	//print job name
	test_name = "-VECTOR EMPTY CONSTRUCTION TEST-";
	print_test_name(count);

	//std working
	timer_start();
	for (int i = 0; i < count; ++i){
		std::vector<int> p1;
	}
	double std_res = timer_stop();
	std::cout << "std result: " << std_res << " sec | " << std::flush;

	//ft working
	timer_start();
	for (int i = 0; i < count; ++i){
		ft::vector<int> p1;
	}
	double ft_res = timer_stop();
	std::cout << "ft result: " << ft_res << " sec | " << std::flush;
	print_result(std_res, ft_res);
}

void test_vector_param_ctor(long count){
	//print job name
	test_name = "-VECTOR PARAM CONSTRUCTION TEST-";
	print_test_name(count);

	//init
    const size_t N = 42;
	std::vector<int> v1(N);
	ft::vector<int> v2(N);

	//output test
	timer_start();
	long err_count = 0;
	for (int i = 0; i < count; ++i){
		int std_res = *(v1.begin() + i % N);
		int ft_res = *(v2.begin() + i % N);
		if (std_res != ft_res)
			++err_count;
	}
	double comp_res = timer_stop();
    print_comp_res(err_count, comp_res);

	//std working
	timer_start();
	for (int i = 0; i < count; ++i){
        std::vector<int> v1(N);
	}
	double std_res = timer_stop();
	std::cout << "std result: " << std_res << " sec | " << std::flush;
	
	//ft working 
	timer_start();
	for (int i = 0; i < count; ++i){
        ft::vector<int> v2(N);
	}
	double ft_res = timer_stop();
	std::cout << "ft result: " << ft_res << " sec | " << std::flush;
	print_result(std_res, ft_res);
}

void test_vector_two_param_ctor(long count){
	//print job name
	test_name = "-VECTOR TWO PARAM CONSTRUCTION TEST-";
	print_test_name(count);

	//init
    const size_t N = 42;
    const int M = 99;
	std::vector<int> v1(N, M);
	ft::vector<int> v2(N, M);

	//output test
	timer_start();
	long err_count = 0;
	for (int i = 0; i < count; ++i){
		int std_res = *(v1.begin() + i % N);
		int ft_res = *(v2.begin() + i % N);
		if (std_res != ft_res)
			++err_count;
	}
	double comp_res = timer_stop();
    print_comp_res(err_count, comp_res);
    
	//std working
	timer_start();
	for (int i = 0; i < count; ++i){
        std::vector<int> v1(N, M);
	}
	double std_res = timer_stop();
	std::cout << "std result: " << std_res << " sec | " << std::flush;
	
	//ft working 
	timer_start();
	for (int i = 0; i < count; ++i){
        ft::vector<int> v2(N, M);
	}
	double ft_res = timer_stop();
	std::cout << "ft result: " << ft_res << " sec | " << std::flush;
	print_result(std_res, ft_res);
}

void test_vector_size_capacity_empty(long count){
	//print job name
	test_name = "-VECTOR SIZE CAPACITY EMPTY TEST-";
	print_test_name(count);

	{ //0 test: size, capacity, empty, max_size
	std::vector<int> v1;
	ft::vector<int> v2;

	//output test
	timer_start();
	long err_count = 0;
	for (int i = 0; i < count; ++i){
		int std_res = v1.size();
		int ft_res = v2.size();
		if (std_res != ft_res)
			++err_count;
		std_res = v1.capacity();
		ft_res = v2.capacity();
		if (std_res != ft_res)
			++err_count;
		size_t std_res_t = v1.max_size();
		size_t ft_res_t = v2.max_size();
		if (std_res_t != ft_res_t)
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
    std::vector<int> v1;
	timer_start();
	for (int i = 0; i < count; ++i){
		v1.size();
		v1.capacity();
		v1.max_size();
		v1.empty();
	}
	double std_res = timer_stop();
	std::cout << "std result: " << std_res << " sec | " << std::flush;
	
	//ft working 
	ft::vector<int> v2;
	timer_start();
	for (int i = 0; i < count; ++i){
		v2.size();
		v2.capacity();
		v2.max_size();
		v2.empty();
	}
	double ft_res = timer_stop();
	std::cout << "ft result: " << ft_res << " sec | " << std::flush;
	print_result(std_res, ft_res);
}

void test_vector_size_capacity_random(long count){
	//print job name
	test_name = "-VECTOR SIZE CAPACITY RANDOM TEST-";
	print_test_name(count);

	//init
    const size_t N = 42;
    const int M = 99;
	srand(time(NULL));
	{ //random test: size, capacity, empty

	//output test
	timer_start();
	long err_count = 0;
	for (int i = 0; i < count; ++i){
	size_t num = rand() % N;
	int fill = rand() % std::numeric_limits<int>::max();
	std::vector<int> v1(num, fill);
	ft::vector<int> v2(num, fill);
		int std_res = v1.size();
		int ft_res = v2.size();
		if (std_res != ft_res)
			++err_count;
		std_res = v1.capacity();
		ft_res = v2.capacity();
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
    std::vector<int> v1(N, M);
	timer_start();
	for (int i = 0; i < count; ++i){
		v1.size();
		v1.capacity();
		v1.empty();
	}
	double std_res = timer_stop();
	std::cout << "std result: " << std_res << " sec | " << std::flush;
	
	//ft working 
	ft::vector<int> v2(N, M);
	timer_start();
	for (int i = 0; i < count; ++i){
		v2.size();
		v2.capacity();
		v2.empty();
	}
	double ft_res = timer_stop();
	std::cout << "ft result: " << ft_res << " sec | " << std::flush;
	print_result(std_res, ft_res);
}

void test_vector_resize(long count){
	//print job name
	test_name = "-VECTOR RESIZE TEST-";
	print_test_name(count);

	//init
    const size_t N = 42;
    const int M = 99;
	srand(time(NULL));
	{
	//output test
	timer_start();
	long err_count = 0;
	for (int i = 0; i < count; ++i){
		size_t num = rand() % N;
		size_t resize_n = rand() % (N * 2);
		int fill = rand() % std::numeric_limits<int>::max();
		std::vector<int> v1(num, fill);
		ft::vector<int> v2(num, fill);
		v1.resize(resize_n);
		v2.resize(resize_n);
		int std_res = v1.size();
		int ft_res = v2.size();
		if (std_res != ft_res)
			++err_count;
		if (!ft::equal(v1.begin(),v1.end(),v2.begin()))
			++err_count;
	}
	double comp_res = timer_stop();
    print_comp_res(err_count, comp_res);
	}

	//std working
	timer_start();
	for (int i = 0; i < count; ++i){
    	std::vector<int> v1(N, M);
		v1.resize(N * 2);
		v1.resize(N / 2);
	}
	double std_res = timer_stop();
	std::cout << "std result: " << std_res << " sec | " << std::flush;
	
	//ft working 
	timer_start();
	for (int i = 0; i < count; ++i){
		ft::vector<int> v2(N, M);
		v2.resize(N * 2);
		v2.resize(N / 2);
	}
	double ft_res = timer_stop();
	std::cout << "ft result: " << ft_res << " sec | " << std::flush;
	print_result(std_res, ft_res);
}

void test_vector_reserve(long count){
	//print job name
	test_name = "-VECTOR RESERVE TEST-";
	print_test_name(count);

	//init
    const size_t N = 42;
    const int M = 99;
	srand(time(NULL));
	{
	//output test
	timer_start();
	long err_count = 0;
	for (int i = 0; i < count; ++i){
		size_t num = rand() % N;
		std::vector<int> v1(num);
		ft::vector<int> v2(num);
		for (size_t i = 0; i < num; ++i){
			int fill = rand() % M;
			v1.push_back(fill);
			v2.push_back(fill);
		}
		size_t reserve_n = rand() % (N * 2);
		v1.reserve(reserve_n);
		v2.reserve(reserve_n);
		int std_res = v1.size();
		int ft_res = v2.size();
		if (std_res != ft_res)
			++err_count;
		std_res = v1.capacity();
		ft_res = v2.capacity();
		if (std_res != ft_res)
			++err_count;
		if (!ft::equal(v1.begin(),v1.end(),v2.begin()))
			++err_count;
	}
	double comp_res = timer_stop();
    print_comp_res(err_count, comp_res);
	}

	//std working
	timer_start();
	for (int i = 0; i < count; ++i){
    	std::vector<int> v1(N, M);
		v1.reserve(N * 2);
	}
	double std_res = timer_stop();
	std::cout << "std result: " << std_res << " sec | " << std::flush;
	
	//ft working 
	timer_start();
	for (int i = 0; i < count; ++i){
		ft::vector<int> v2(N, M);
		v2.reserve(N * 2);
	}
	double ft_res = timer_stop();
	std::cout << "ft result: " << ft_res << " sec | " << std::flush;
	print_result(std_res, ft_res);
}

void test_vector_push_back(long count){
	//print job name
	test_name = "-VECTOR PUSH BACK TEST-";
	print_test_name(count);

	//init
    const size_t N = 21;
    const int M = std::numeric_limits<int>::max();
	srand(time(NULL));
	{
	//output test
	timer_start();
	long err_count = 0;
	for (int i = 0; i < count; ++i){
		std::vector<int> v1(N);
		ft::vector<int> v2(N);
		for (size_t i = 0; i < N * 2; ++i){
			int fill = rand() % M;
			v1.push_back(fill);
			v2.push_back(fill);
		}		
		int std_res = v1.size();
		int ft_res = v2.size();
		if (std_res != ft_res)
			++err_count;
		if (!ft::equal(v1.begin(),v1.end(),v2.begin()))
			++err_count;
	}
	double comp_res = timer_stop();
    print_comp_res(err_count, comp_res);
	}

	//std working
    std::vector<int> v1;
	timer_start();
	for (int i = 0; i < count; ++i){
		v1.push_back(N);
	}
	double std_res = timer_stop();
	std::cout << "std result: " << std_res << " sec | " << std::flush;
	
	//ft working 
	ft::vector<int> v2;
	timer_start();
	for (int i = 0; i < count; ++i){
		v2.push_back(N);
	}
	double ft_res = timer_stop();
	std::cout << "ft result: " << ft_res << " sec | " << std::flush;
	print_result(std_res, ft_res);
}

void test_vector_pop_back(long count){
	//print job name
	test_name = "-VECTOR POP BACK TEST-";
	print_test_name(count);

	//init
    const size_t N = 42;
    const int M = std::numeric_limits<int>::max();
	srand(time(NULL));
	{
	//output test
	timer_start();
	long err_count = 0;
	for (int i = 0; i < count; ++i){
		size_t num = rand() % N;
		std::vector<int> v1(num);
		ft::vector<int> v2(num);
		for (size_t i = 0; i < num; ++i){
			int fill = rand() % M;
			v1.push_back(fill);
			v2.push_back(fill);
		}
		if (num) { 
			size_t del = rand() % num;
			for (size_t i = 0; i < del; ++i){
				v1.pop_back();
				v2.pop_back();
			}
		}
		int std_res = v1.size();
		int ft_res = v2.size();
		if (std_res != ft_res)
			++err_count;
		if (!ft::equal(v1.begin(),v1.end(),v2.begin()))
			++err_count;
	}
	double comp_res = timer_stop();
    print_comp_res(err_count, comp_res);
	}

	//std working
    std::vector<int> v1(count, M);
	timer_start();
	for (int i = 0; i < count; ++i){
		v1.pop_back();
	}
	double std_res = timer_stop();
	std::cout << "std result: " << std_res << " sec | " << std::flush;
	
	//ft working 
	ft::vector<int> v2(count, M);
	timer_start();
	for (int i = 0; i < count; ++i){
		v2.pop_back();
	}
	double ft_res = timer_stop();
	std::cout << "ft result: " << ft_res << " sec | " << std::flush;
	print_result(std_res, ft_res);
}

void test_vector_erase_pos(long count){
	//print job name
	test_name = "-VECTOR ERASE POS TEST-";
	print_test_name(count);

	//init
    const size_t N = 42;
    const int M = std::numeric_limits<int>::max();
	srand(time(NULL));
	{
	//output test
	timer_start();
	long err_count = 0;
	for (int i = 0; i < count; ++i){
		size_t num = rand() % N;
		std::vector<int> v1;
		ft::vector<int> v2;
		for (size_t i = 0; i < num; ++i){
			int fill = rand() % M;
			v1.push_back(fill);
			v2.push_back(fill);
		}
		if (!num) continue;
		size_t it_pos = rand() % num;
		std::vector<int>::iterator it = v1.begin() + it_pos;
		ft::vector<int>::iterator its = v2.begin() + it_pos;
		std::vector<int>::iterator res_std = v1.erase(it);
		ft::vector<int>::iterator res_ft = v2.erase(its);
		if (res_std != v1.end() && res_ft != v2.end() && *res_std != *res_ft)
		 	++err_count;
		if (res_std - v1.begin() != res_ft - v2.begin())
			++err_count;
		int std_res = v1.size();
		int ft_res = v2.size();
		if (std_res != ft_res)
			++err_count;
		if (!ft::equal(v1.begin(),v1.end(),v2.begin()))
			++err_count;
	}
	double comp_res = timer_stop();
    print_comp_res(err_count, comp_res);
	}

	//std working
    std::vector<int> v1(count, M);
	timer_start();
	for (int i = 0; i < count; ++i){
		v1.erase(v1.begin());
	}
	double std_res = timer_stop();
	std::cout << "std result: " << std_res << " sec | " << std::flush;
	
	//ft working 
	ft::vector<int> v2(count, M);
	timer_start();
	for (int i = 0; i < count; ++i){
		v2.erase(v2.begin());
	}
	double ft_res = timer_stop();
	std::cout << "ft result: " << ft_res << " sec | " << std::flush;
	print_result(std_res, ft_res);
}

void test_vector_erase_iter(long count){
	//print job name
	test_name = "-VECTOR ERASE ITER TEST-";
	print_test_name(count);

	//init
    const size_t N = 42;
    const int M = std::numeric_limits<int>::max();
	srand(time(NULL));
	{
	//output test
	timer_start();
	long err_count = 0;
	for (int i = 0; i < count; ++i){
		size_t num = rand() % N;
		std::vector<int> v1;
		ft::vector<int> v2;
		for (size_t i = 0; i < num; ++i){
			int fill = rand() % M;
			v1.push_back(fill);
			v2.push_back(fill);
		}
		if (!num) continue;
		size_t it_pos = rand() % num;
		std::vector<int>::iterator it = v1.begin() + it_pos;
		ft::vector<int>::iterator its = v2.begin() + it_pos;
		std::vector<int>::iterator res_std = v1.erase(v1.begin(), it);
		ft::vector<int>::iterator res_ft = v2.erase(v2.begin(), its);
		if (res_std != v1.end() && res_ft != v2.end() && *res_std != *res_ft)
		 	++err_count;
		if (res_std - v1.begin() != res_ft - v2.begin())
			++err_count;
		int std_res = v1.size();
		int ft_res = v2.size();
		if (std_res != ft_res)
			++err_count;
		if (!ft::equal(v1.begin(),v1.end(),v2.begin()))
			++err_count;
	}
	double comp_res = timer_stop();
    print_comp_res(err_count, comp_res);
	}

	//std working
    std::vector<int> v1(count, M);
	timer_start();
	for (int i = 0; i < count; ++i){
		v1.erase(v1.begin(), v1.begin() + 1);
	}
	double std_res = timer_stop();
	std::cout << "std result: " << std_res << " sec | " << std::flush;
	
	//ft working 
	ft::vector<int> v2(count, M);
	timer_start();
	for (int i = 0; i < count; ++i){
		v2.erase(v2.begin(), v2.begin() + 1);
	}
	double ft_res = timer_stop();
	std::cout << "ft result: " << ft_res << " sec | " << std::flush;
	print_result(std_res, ft_res);
}

void test_vector_clear(long count){
	//print job name
	test_name = "-VECTOR CLEAR TEST-";
	print_test_name(count);

	//init
    const size_t N = 42;
    const int M = std::numeric_limits<int>::max();
	srand(time(NULL));
	{
	//output test
	timer_start();
	long err_count = 0;
	for (int i = 0; i < count; ++i){
		size_t num = rand() % N;
		std::vector<int> v1;
		ft::vector<int> v2;
		for (size_t i = 0; i < num; ++i){
			int fill = rand() % M;
			v1.push_back(fill);
			v2.push_back(fill);
		}
		v1.clear();
		v2.clear();
		int std_res = v1.size();
		int ft_res = v2.size();
		if (std_res != ft_res)
			++err_count;
		if (!ft::equal(v1.begin(),v1.end(),v2.begin()))
			++err_count;
	}
	double comp_res = timer_stop();
    print_comp_res(err_count, comp_res);
	}

	//std working
    
	timer_start();
	for (int i = 0; i < count; ++i){
		std::vector<int> v1(N * N / 2, M);
		v1.clear();
	}
	double std_res = timer_stop();
	std::cout << "std result: " << std_res << " sec | " << std::flush;
	
	//ft working 
	timer_start();
	for (int i = 0; i < count; ++i){
		ft::vector<int> v2(N * N / 2, M);
		v2.clear();
	}
	double ft_res = timer_stop();
	std::cout << "ft result: " << ft_res << " sec | " << std::flush;
	print_result(std_res, ft_res);
}

void test_vector_reverse_iter(long count){
	//print job name
	test_name = "-VECTOR REVERSE ITER TEST-";
	print_test_name(count);

	//init
    const size_t N = 42;
    const int M = std::numeric_limits<int>::max();
	srand(time(NULL));
	{
	//output test
	timer_start();
	long err_count = 0;
	for (int i = 0; i < count; ++i){
		size_t num = rand() % N;
		if (!num) continue;
		std::vector<int> v1;
		ft::vector<int> v2;
		for (size_t i = 0; i < num; ++i){
			int fill = rand() % M;
			v1.push_back(fill);
			v2.push_back(fill);
		}
		std::vector<int>::reverse_iterator it_rb = v1.rbegin();
		std::vector<int>::reverse_iterator it_re = v1.rend();
		ft::vector<int>::reverse_iterator its_rb = v2.rbegin();
		ft::vector<int>::reverse_iterator its_re = v2.rend();

		if (*it_rb != *its_rb)
			++err_count;
		if (it_rb - it_re != its_rb - its_re)
			++err_count;
		if (!ft::equal(it_rb, it_re, its_rb))
			++err_count;
	}
	double comp_res = timer_stop();
    print_comp_res(err_count, comp_res);
	}
}

void test_vector_swap(long count){
	//print job name
	test_name = "-VECTOR SWAP TEST-";
	print_test_name(count);

	//init
    const size_t N1 = 21;
    const size_t N2 = 42;
    const int M1 = 99;
    const int M2 = 44;
	{
	//output test
	timer_start();
	long err_count = 0;
	for (int i = 0; i < count; ++i){
		ft::vector<int> v1(N1, M1);
		ft::vector<int> v2(N2, M2);

		v1.swap(v2);
		if (v1.size() != N2) ++err_count;
		if (v2.size() != N1) ++err_count;
		if (*(v1.begin()) != M2) ++err_count;
		if (*(v2.begin()) != M1) ++err_count;
		if (v1.capacity() != N2) ++err_count;
		if (v2.capacity() != N1) ++err_count;
		
		ft::swap(v1, v2);
		if (v1.size() != N1) ++err_count;
		if (v2.size() != N2) ++err_count;
		if (*(v1.begin()) != M1) ++err_count;
		if (*(v2.begin()) != M2) ++err_count;
		if (v1.capacity() != N1) ++err_count;
		if (v2.capacity() != N2) ++err_count;
	}
	double comp_res = timer_stop();
    print_comp_res(err_count, comp_res);
	}
	
	//std working
    std::vector<int> v1(count, M1);
    std::vector<int> v2(count, M2);
	timer_start();
	for (int i = 0; i < count; ++i)
	v1.swap(v2);
	double std_res = timer_stop();
	std::cout << "std result: " << std_res << " sec | " << std::flush;
	
	//ft working 
	ft::vector<int> v3(count, M1);
	ft::vector<int> v4(count, M2);
	timer_start();
	for (int i = 0; i < count; ++i)
	v3.swap(v4);
	double ft_res = timer_stop();
	std::cout << "ft result: " << ft_res << " sec | " << std::flush;
	print_result(std_res, ft_res);
}

void test_vector_insert_pos(long count){
	//print job name
	test_name = "-VECTOR INSERT POS TEST-";
	print_test_name(count);

	//init
    const size_t N = 42;
    const int M = std::numeric_limits<int>::max();
	srand(time(NULL));
	{
	//output test
	timer_start();
	long err_count = 0;
	for (int i = 0; i < count; ++i){
		size_t num = rand() % N;
		std::vector<int> v1;
		ft::vector<int> v2;
		for (size_t i = 0; i < num; ++i){
			int fill = rand() % M;
			v1.push_back(fill);
			v2.push_back(fill);
		}
		if (!num) continue;
		size_t it_pos = rand() % num;
		std::vector<int>::iterator it = v1.begin() + it_pos;
		ft::vector<int>::iterator its = v2.begin() + it_pos;
		std::vector<int>::iterator res_std = v1.insert(it, N);
		ft::vector<int>::iterator res_ft = v2.insert(its, N);
		if (*res_std != *res_ft)
		 	++err_count;
		if (res_std - v1.begin() != res_ft - v2.begin())
			++err_count;
		int std_res = v1.size();
		int ft_res = v2.size();
		if (std_res != ft_res)
			++err_count;
		if (!ft::equal(v1.begin(),v1.end(),v2.begin()))
			++err_count;
	}
	double comp_res = timer_stop();
    print_comp_res(err_count, comp_res);
	}

	//std working
    std::vector<int> v1(N, M);
	timer_start();
	for (int i = 0; i < count; ++i){
		v1.insert(v1.begin(), N);
	}
	double std_res = timer_stop();
	std::cout << "std result: " << std_res << " sec | " << std::flush;
	
	//ft working 
	ft::vector<int> v2(N, M);
	timer_start();
	for (int i = 0; i < count; ++i){
		v2.insert(v2.begin(), N);
	}
	double ft_res = timer_stop();
	std::cout << "ft result: " << ft_res << " sec | " << std::flush;
	print_result(std_res, ft_res);
}

void test_vector_insert_pos_num(long count){
	//print job name
	test_name = "-VECTOR INSERT POS NUM TEST-";
	print_test_name(count);

	//init
    const size_t N = 42;
    const int M = std::numeric_limits<int>::max();
	srand(time(NULL));
	{
	//output test
	timer_start();
	long err_count = 0;
	for (int i = 0; i < count; ++i){
		size_t num = rand() % N;
		std::vector<int> v1;
		ft::vector<int> v2;
		for (size_t i = 0; i < num; ++i){
			int fill = rand() % M;
			v1.push_back(fill);
			v2.push_back(fill);
		}
		if (!num) continue;
		size_t it_pos = rand() % num;
		int fill = rand() % N;
		std::vector<int>::iterator it = v1.begin() + it_pos;
		ft::vector<int>::iterator its = v2.begin() + it_pos;
		v1.insert(it, (size_t) fill, fill);
		v2.insert(its, (size_t) fill, fill);
		int std_res = v1.size();
		int ft_res = v2.size();
		if (std_res != ft_res)
			++err_count;
		if (!ft::equal(v1.begin(),v1.end(),v2.begin()))
			++err_count;
	}
	double comp_res = timer_stop();
    print_comp_res(err_count, comp_res);
	}

	//std working
    std::vector<int> v1(N, M);
	timer_start();
	for (int i = 0; i < count; ++i){
		v1.insert(v1.begin(), (size_t) 1, 42);
	}
	double std_res = timer_stop();
	std::cout << "std result: " << std_res << " sec | " << std::flush;
	
	//ft working 
	ft::vector<int> v2(N, M);
	timer_start();
	for (int i = 0; i < count; ++i){
		v2.insert(v2.begin(), (size_t) 1, 42);
	}
	double ft_res = timer_stop();
	std::cout << "ft result: " << ft_res << " sec | " << std::flush;
	print_result(std_res, ft_res);
}

void test_vector_insert_iter(long count){
	//print job name
	test_name = "-VECTOR INSERT ITERATOR TEST-";
	print_test_name(count);

	//init
    const size_t N = 42;
    const int M = std::numeric_limits<int>::max();
	srand(time(NULL));
	{
	//output test
	timer_start();
	long err_count = 0;
	for (int i = 0; i < count; ++i){
		size_t num = rand() % N;
		std::vector<int> v1;
		std::vector<int> v1_s;
		ft::vector<int> v2;
		ft::vector<int> v2_s;
		for (size_t i = 0; i < num; ++i){
			int fill = rand() % M;
			v1.push_back(fill);
			v2.push_back(fill);
			fill = rand() % M;
			v1_s.push_back(fill);
			v2_s.push_back(fill);
		}
		if (!num) continue;
		size_t it_pos = rand() % num;
		std::vector<int>::iterator it = v1.begin() + it_pos;
		ft::vector<int>::iterator its = v2.begin() + it_pos;
		v1.insert(it, v1_s.begin(), (v1_s.begin() + it_pos));
		v2.insert(its, v2_s.begin(), (v2_s.begin() + it_pos));
		int std_res = v1.size();
		int ft_res = v2.size();
		if (std_res != ft_res)
			++err_count;
		if (!ft::equal(v1.begin(),v1.end(),v2.begin()))
			++err_count;
	}
	double comp_res = timer_stop();
    print_comp_res(err_count, comp_res);
	}

	//std working
    std::vector<int> v1(N, M);
    std::vector<int> v1_s(1, M);
	timer_start();
	for (int i = 0; i < count; ++i){
		v1.insert(v1.begin(), v1_s.begin(), v1_s.end());
	}
	double std_res = timer_stop();
	std::cout << "std result: " << std_res << " sec | " << std::flush;
	
	//ft working 
	ft::vector<int> v2(N, M);
	ft::vector<int> v2_s(N, M);
	timer_start();
	for (int i = 0; i < count; ++i){
		v2.insert(v2.begin(), v1_s.begin(), v1_s.end());
	}
	double ft_res = timer_stop();
	std::cout << "ft result: " << ft_res << " sec | " << std::flush;
	print_result(std_res, ft_res);
}

void test_vector_comparison(long count){
	//print job name
	test_name = "-VECTOR COMPARISON TEST-";
	print_test_name(count);

	//init
    const size_t N = 42;
    const int M = std::numeric_limits<int>::max();
	srand(time(NULL));
	{
	//output test
	timer_start();
	long err_count = 0;
	for (int i = 0; i < count; ++i){
		size_t num = rand() % N;
		std::vector<int> v1(N);
		std::vector<int> v1_s(N);
		ft::vector<int> v2(N);
		ft::vector<int> v2_s(N);
		for (size_t i = 0; i < num; ++i){
			int fill = rand() % M;
			v1.push_back(fill);
			v1_s.push_back(fill);
			v2.push_back(fill);
			v2_s.push_back(fill);
		}
		if ((v1==v1_s) != (v2==v2_s)) ++err_count;
		if ((v1<v1_s) != (v2<v2_s)) ++err_count;
		if ((v1!=v1_s) != (v2!=v2_s)) ++err_count;
		if ((v1>v1_s) != (v2>v2_s)) ++err_count;
		if ((v1<=v1_s) != (v2<=v2_s)) ++err_count;
		if ((v1>=v1_s) != (v2>=v2_s)) ++err_count;
	}
	double comp_res = timer_stop();
    print_comp_res(err_count, comp_res);
	}
}

void test_vector_assign_range(long count){
	//print job name
	test_name = "-VECTOR ASSIGN RANGE TEST-";
	print_test_name(count);

	//init
    const size_t N = 42;
    const int M = std::numeric_limits<int>::max();
	srand(time(NULL));
	{
	//output test
	timer_start();
	long err_count = 0;
	for (int i = 0; i < count; ++i){
		size_t num = rand() % N;
		std::vector<int> v1;
		ft::vector<int> v2;
		for (size_t i = 0; i < num; ++i){
			int fill = rand() % M;
			v1.push_back(fill);
			v2.push_back(fill);
		}
		std::vector<int> v1_r;
		ft::vector<int> v2_r;
		v1_r.assign(v1.begin(), v1.end());
		v2_r.assign(v2.begin(), v2.end());
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
    std::vector<int> v1(N * N, M);
	timer_start();
	for (int i = 0; i < count; ++i){
    	std::vector<int> v1_r;
		v1_r.assign(v1.begin(), v1.end());
	}
	double std_res = timer_stop();
	std::cout << "std result: " << std_res << " sec | " << std::flush;
	
	//ft working
	ft::vector<int> v2(N * N, M);
	timer_start();
	for (int i = 0; i < count; ++i){
		ft::vector<int> v2_r;
		v2_r.assign(v2.begin(), v2.end());
	}
	double ft_res = timer_stop();
	std::cout << "ft result: " << ft_res << " sec | " << std::flush;
	print_result(std_res, ft_res);
}

void test_vector_assign_n(long count){
	//print job name
	test_name = "-VECTOR ASSIGN NUM TEST-";
	print_test_name(count);

	//init
    const size_t N = 42;
    const int M = std::numeric_limits<int>::max();
	srand(time(NULL));
	{
	//output test
	timer_start();
	long err_count = 0;
	for (int i = 0; i < count; ++i){
		size_t num = rand() % N;
		int fill = rand() % M;
		std::vector<int> v1;
		ft::vector<int> v2;

		v1.assign(num, fill);
		v2.assign(num, fill);
		int std_res = v1.size();
		int ft_res = v2.size();
#if PRINT
		std::cout << "v1 size: " << std_res << " v2_size: " << ft_res << std::endl;
		std::cout << "std content:\n";
		for (size_t i = 0; i < v1_r.size(); ++i){
			std::cout << *(v1_r.begin() + i) << " "; 
		}
		std::cout << std::endl;
		std::cout << "ft content:\n";
		for (size_t i = 0; i < v2_r.size(); ++i){
			std::cout << *(v2_r.begin() + i) << " "; 
		}
		std::cout << std::endl;
#endif
		if (std_res != ft_res)
			++err_count;
		if (!ft::equal(v1.begin(),v1.end(),v2.begin()))
			++err_count;
	}
	double comp_res = timer_stop();
    print_comp_res(err_count, comp_res);
	}

	//std working
	timer_start();
	for (int i = 0; i < count; ++i){
    std::vector<int> v1;
		v1.assign(N * N, M);
	}
	double std_res = timer_stop();
	std::cout << "std result: " << std_res << " sec | " << std::flush;
	
	//ft working
	timer_start();
	for (int i = 0; i < count; ++i){
	ft::vector<int> v2;
		v2.assign(N * N, M);
	}
	double ft_res = timer_stop();
	std::cout << "ft result: " << ft_res << " sec | " << std::flush;
	print_result(std_res, ft_res);
}

void test_vector_assignment(long count){
	//print job name
	test_name = "-VECTOR ASSIGNMENT OP TEST-";
	print_test_name(count);

	//init
    const size_t N = 42;
    const int M = std::numeric_limits<int>::max();
	srand(time(NULL));
	{
	//output test
	timer_start();
	long err_count = 0;
	for (int i = 0; i < count; ++i){
		size_t num = rand() % N;
		std::vector<int> v1;
		ft::vector<int> v2;
		for (size_t i = 0; i < num; ++i){
			int fill = rand() % M;
			v1.push_back(fill);
			v2.push_back(fill);
		}
		std::vector<int> v1_r;
		ft::vector<int> v2_r;
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
    std::vector<int> v1(N * N, M);
	timer_start();
	for (int i = 0; i < count; ++i){
    	std::vector<int> v1_r;
		v1_r = v1;
	}
	double std_res = timer_stop();
	std::cout << "std result: " << std_res << " sec | " << std::flush;
	
	//ft working
	ft::vector<int> v2(N * N, M);
	timer_start();
	for (int i = 0; i < count; ++i){
		ft::vector<int> v2_r;
		v2_r = v2;
	}
	double ft_res = timer_stop();
	std::cout << "ft result: " << ft_res << " sec | " << std::flush;
	print_result(std_res, ft_res);
}

void test_vector_copy_ctor(long count){
	//print job name
	test_name = "-VECTOR COPY CONSTRUCTOR TEST-";
	print_test_name(count);

	//init
    const size_t N = 42;
    const int M = std::numeric_limits<int>::max();
	srand(time(NULL));
	{
	//output test
	timer_start();
	long err_count = 0;
	for (int i = 0; i < count; ++i){
		size_t num = rand() % N;
		std::vector<int> v1;
		ft::vector<int> v2;
		for (size_t i = 0; i < num; ++i){
			int fill = rand() % M;
			v1.push_back(fill);
			v2.push_back(fill);
		}
		// if (!num) continue;
		std::vector<int> v1_r(v1);
		ft::vector<int> v2_r(v2);
		int std_res = v1_r.size();
		int ft_res = v2_r.size();
#if PRINT
		std::cout << "v1 size: " << std_res << " v2_size: " << ft_res << std::endl;
		std::cout << "std content:\n";
		for (size_t i = 0; i < v1_r.size(); ++i){
			std::cout << *(v1_r.begin() + i) << " "; 
		}
		std::cout << std::endl;
		std::cout << "ft content:\n";
		for (size_t i = 0; i < v2_r.size(); ++i){
			std::cout << *(v2_r.begin() + i) << " "; 
		}
		std::cout << std::endl;
#endif
		if (std_res != ft_res)
			++err_count;
		if (!ft::equal(v1_r.begin(),v1_r.end(),v2_r.begin()))
			++err_count;
	}
	double comp_res = timer_stop();
    print_comp_res(err_count, comp_res);
	}

	//std working
    std::vector<int> v1(N * N, M);
	timer_start();
	for (int i = 0; i < count; ++i){
	    std::vector<int> v1_r(v1);
	}
	double std_res = timer_stop();
	std::cout << "std result: " << std_res << " sec | " << std::flush;
	
	//ft working
	ft::vector<int> v2(N * N, M);
	timer_start();
	for (int i = 0; i < count; ++i){
		ft::vector<int> v2_r(v2);
	}
	double ft_res = timer_stop();
	std::cout << "ft result: " << ft_res << " sec | " << std::flush;
	print_result(std_res, ft_res);
}

void test_vector_copy_range_ctor(long count){
	//print job name
	test_name = "-VECTOR COPY RANGE CONSTRUCTOR TEST-";
	print_test_name(count);

	//init
    const size_t N = 42;
    const int M = std::numeric_limits<int>::max();
	srand(time(NULL));
	{
	//output test
	timer_start();
	long err_count = 0;
	for (int i = 0; i < count; ++i){
		size_t num = rand() % N;
		std::vector<int> v1;
		ft::vector<int> v2;
		for (size_t i = 0; i < num; ++i){
			int fill = rand() % M;
			v1.push_back(fill);
			v2.push_back(fill);
		}
		// if (!num) continue;
		std::vector<int> v1_r(v1.begin(), v1.end());
		ft::vector<int> v2_r(v2.begin(), v2.end());
		int std_res = v1_r.size();
		int ft_res = v2_r.size();
#if PRINT
		std::cout << "v1 size: " << std_res << " v2_size: " << ft_res << std::endl;
		std::cout << "std content:\n";
		for (size_t i = 0; i < v1_r.size(); ++i){
			std::cout << *(v1_r.begin() + i) << " "; 
		}
		std::cout << std::endl;
		std::cout << "ft content:\n";
		for (size_t i = 0; i < v2_r.size(); ++i){
			std::cout << *(v2_r.begin() + i) << " "; 
		}
		std::cout << std::endl;
#endif
		if (std_res != ft_res)
			++err_count;
		if (!ft::equal(v1_r.begin(),v1_r.end(),v2_r.begin()))
			++err_count;
	}
	double comp_res = timer_stop();
    print_comp_res(err_count, comp_res);
	}

	//std working
    std::vector<int> v1(N * N, M);
	timer_start();
	for (int i = 0; i < count; ++i){
	    std::vector<int> v1_r(v1.begin(), v1.end());
	}
	double std_res = timer_stop();
	std::cout << "std result: " << std_res << " sec | " << std::flush;
	
	//ft working
	ft::vector<int> v2(N * N, M);
	timer_start();
	for (int i = 0; i < count; ++i){
		ft::vector<int> v2_r(v2.begin(), v2.end());
	}
	double ft_res = timer_stop();
	std::cout << "ft result: " << ft_res << " sec | " << std::flush;
	print_result(std_res, ft_res);
}

void test_vector_access(long count){
	//print job name
	test_name = "-VECTOR ACCESS TEST-";
	print_test_name(count);

	//init
    const size_t N = 42;
    const int M = std::numeric_limits<int>::max();
	srand(time(NULL));
	{
	//output test
	timer_start();
	long err_count = 0;
	for (int i = 0; i < count; ++i){
		size_t num = rand() % N;
		std::vector<int> v1;
		ft::vector<int> v2;
		for (size_t i = 0; i < num; ++i){
			int fill = rand() % M;
			v1.push_back(fill);
			v2.push_back(fill);
		}
		if (!num) continue;
		int std_res = v1.size();
		int ft_res = v2.size();
		if (std_res != ft_res) ++err_count;
		if (v1.front() != v2.front()) ++err_count;
		if (v1.back() != v2.back()) ++err_count;
		size_t pos = rand() % num;
		if (v1.at(pos) != v2.at(pos)) ++err_count;
		if (v1[pos] != v2[pos]) ++err_count;

	}
	double comp_res = timer_stop();
    print_comp_res(err_count, comp_res);
	}
}
