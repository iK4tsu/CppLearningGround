#include <algorithm>
#include <chrono>
#include <execution>
#include <iostream>
#include <mutex>
#include <random>
#include <vector>

// uncomment to run examples 1, 2, 3 in parallel
// #define PAR

/*
Simple timer helper.
*/
struct Timer
{
	void start() { m_start = std::chrono::steady_clock::now(); }
	auto peek()
	{
		using namespace std::chrono;
		return duration_cast<microseconds>(steady_clock::now() - m_start).count() / 1'000'000.0;
	}


private:
	std::chrono::time_point<std::chrono::steady_clock> m_start{};
	std::chrono::time_point<std::chrono::steady_clock> m_now{};
};

/*
Basic usage of parallelism in C++
std::sort is one the functions that better fits this feature
*/
void example1()
{
	std::mt19937_64 rnd{72}; // seeded rand num
	std::uniform_real_distribution<float> uniform(0, 100); // rand distribution
	auto rng = [&] { return uniform(rnd); }; // rand generator

	constexpr size_t n = 50'000'000;
	std::vector<float> vec(n); // vector of n length
	std::generate(vec.begin(), vec.end(), rng); // fills vec with rand numbers

	Timer timer;
	timer.start();
#ifdef PAR
	std::sort(std::execution::par, vec.begin(), vec.end());
#else
	std::sort(vec.begin(), vec.end());
#endif
	auto end = timer.peek();
	std::cout << "Time: " << end << 's' << std::endl;
}

/*
Using parallelism with simpler algorithms may not result in the expected time
improvement. Although that in this case there is an improvement, it has less of
an impact than an algorithm of higher complexity
*/
void example2()
{
	std::mt19937_64 rnd{72}; // seeded rand num
	std::uniform_real_distribution<float> uniform(0, 100); // rand distribution
	auto rng = [&] { return uniform(rnd); }; // rand generator

	constexpr size_t n = 50'000'000;
	std::vector<float> vec(n); // vector of n length
	std::generate(vec.begin(), vec.end(), rng); // fills vec with rand numbers

	Timer timer;
	timer.start();
#ifdef PAR
	std::transform(std::execution::par, vec.begin(), vec.end(), vec.begin(), [](const auto val) {
		return val * 2;
	});
#else
	std::transform(vec.begin(), vec.end(), vec.begin(), [](const auto val) {
		return val * 2;
	});
#endif
	auto end = timer.peek();
	std::cout << "Time: " << end << 's' << std::endl;
}

/*
Here we can see the actual difference said in the previous example, the time
improvement is much more significant.
*/
void example3()
{
	std::mt19937_64 rnd{72}; // seeded rand num
	std::uniform_real_distribution<float> uniform(0, 100); // rand distribution
	auto rng = [&] { return uniform(rnd); }; // rand generator

	constexpr size_t n = 50'000'000;
	std::vector<float> vec(n); // vector of n length
	std::generate(vec.begin(), vec.end(), rng); // fills vec with rand numbers

	Timer timer;
	timer.start();
#ifdef PAR
	std::transform(std::execution::par, vec.begin(), vec.end(), vec.begin(), [](const auto val) {
		const auto x = std::acos(1.0 / val);
		return std::pow(x, x);
	});
#else
	std::transform(vec.begin(), vec.end(), vec.begin(), [](const auto val) {
		const auto x = std::acos(1.0 / val);
		return std::pow(x, x);
	});
#endif
	auto end = timer.peek();
	std::cout << "Time: " << end << 's' << std::endl;
}

/*
Using parallelism isn't just about speed. Most times order matters. An algorithm
that produces the output 'x' in a single threaded environment should produce the
same with multithread.
*/
void example4()
{
	std::mt19937_64 rnd{72}; // seeded rand num
	std::uniform_real_distribution<float> uniform(0, 100); // rand distribution
	auto rng = [&] { return uniform(rnd); }; // rand generator

	constexpr size_t n = 50'000'000;
	std::vector<float> vecA(n); // vector of n length
	std::vector<float> vecB(n); // vector of n length

	std::for_each(std::execution::par, vecA.begin(), vecA.end(), [&rng](auto& val) {
		val = rng();
	});

	rnd.seed(72);

	std::for_each(vecB.begin(), vecB.end(), [&rng](auto& val) {
		val = rng();
	});

	std::cout << "Same content: " << std::boolalpha << (vecA == vecB) << std::endl;
}

/*
We should be careful of how we introduce parallelism. If the object isn't thread
safe we risk ourselves into corrupting the object. Not even sorting the
information afterwards can save the data produced.
*/
void example5()
{
	std::mt19937_64 rnd{72}; // seeded rand num
	std::uniform_real_distribution<float> uniform(0, 100); // rand distribution
	auto rng = [&] { return uniform(rnd); }; // rand generator

	constexpr size_t n = 100'000'00;
	std::vector<float> vecA(n); // vector of n length
	std::vector<float> vecB(n); // vector of n length

	std::for_each(std::execution::par, vecA.begin(), vecA.end(), [&rng](auto& val) {
		val = rng();
	});

	rnd.seed(72);

	std::for_each(vecB.begin(), vecB.end(), [&rng](auto& val) {
		val = rng();
	});

	// rnd is being corrupted!!
	std::sort(std::execution::par, vecA.begin(), vecA.end());
	std::sort(std::execution::par, vecB.begin(), vecB.end());
	std::cout << "Same content: " << std::boolalpha << (vecA == vecB) << std::endl;
}

/*
Fixing the previous issue is simple, just use a lock! Now we don't have race
condition issues.
*/
void example6()
{
	std::mt19937_64 rnd{72}; // seeded rand num
	std::uniform_real_distribution<float> uniform(0, 100); // rand distribution
	auto rng = [&] { return uniform(rnd); }; // rand generator

	constexpr size_t n = 100'000'00;
	std::vector<float> vecA(n); // vector of n length
	std::vector<float> vecB(n); // vector of n length

	std::mutex mtx;

	std::for_each(std::execution::par, vecA.begin(), vecA.end(), [&rng,&mtx](auto& val) {
		std::lock_guard<std::mutex> lock(mtx);
		val = rng();
	});

	rnd.seed(72);

	std::for_each(vecB.begin(), vecB.end(), [&rng](auto& val) {
		val = rng();
	});

	std::sort(std::execution::par, vecA.begin(), vecA.end());
	std::sort(std::execution::par, vecB.begin(), vecB.end());
	std::cout << "Same content: " << std::boolalpha << (vecA == vecB) << std::endl;
}

/*
Fixing the issue now introduces a new one. We have the executable working with
parallelism, however that comes with a cost of performance. Now the parallel
solution is much slower than the single threaded one!
*/
void example7()
{
	std::mt19937_64 rnd{72}; // seeded rand num
	std::uniform_real_distribution<float> uniform(0, 100); // rand distribution
	auto rng = [&] { return uniform(rnd); }; // rand generator

	constexpr size_t n = 100'000'00;
	std::vector<float> vecA(n); // vector of n length
	std::vector<float> vecB(n); // vector of n length

	std::mutex mtx;

	Timer timer;
	timer.start();
	std::for_each(std::execution::par, vecA.begin(), vecA.end(), [&rng,&mtx](auto& val) {
		std::lock_guard<std::mutex> lock(mtx);
		val = rng();
	});
	auto endPar = timer.peek();
	std::cout << "Time par: " << endPar << 's' << std::endl;

	rnd.seed(72);

	timer.start();
	std::for_each(vecB.begin(), vecB.end(), [&rng](auto& val) {
		val = rng();
	});
	auto endSeq = timer.peek();
	std::cout << "Time seq: " << endSeq << 's' << std::endl;
}

int main()
{
	example1();
	example2();
	example3();
	example4();
	example5();
	example6();
	example7();

	return 0;
}
