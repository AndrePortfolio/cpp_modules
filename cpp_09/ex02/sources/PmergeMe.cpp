/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrealbuquerque <andrealbuquerque@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 13:19:02 by andrealbuqu       #+#    #+#             */
/*   Updated: 2024/10/01 14:06:51 by andrealbuqu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/headers.hpp"

/*----------------------------------------------------------------------------*/
/*-------------------------- Constructors & Destructor -----------------------*/
/*----------------------------------------------------------------------------*/

PmergeMe::PmergeMe() : vec(), lst() , vectorSpeed(0), listSpeed(0) {}

PmergeMe::PmergeMe(int argc, char* argv[]) : vec(), lst() , vectorSpeed(0),
										listSpeed(0), vDataTime(0), lDataTime(0)
{
	checkInput(argc, argv);
	printState("Before: ");
	sort();
	printState("After:  ");
	printSpeeds();
}

PmergeMe::PmergeMe(const PmergeMe &copy)
{
	*this = copy;
}

PmergeMe::~PmergeMe() {}

/*----------------------------------------------------------------------------*/
/*--------------------------------- Operator ---------------------------------*/
/*----------------------------------------------------------------------------*/

PmergeMe&	PmergeMe::operator=(const PmergeMe &other)
{
	if (this != &other)
	{
		this->vec = other.vec;
		this->lst = other.lst;
	}
	return (*this);
}

/*----------------------------------------------------------------------------*/
/*------------------------------ Member Functions ----------------------------*/
/*----------------------------------------------------------------------------*/

void	PmergeMe::checkInput(int argc, char* argv[])
{
	if (argc < 2)
		throw std::invalid_argument("Usage: ./RPN <integerSequence>");

	std::clock_t	lDataStart = std::clock();
	for (int i = 1; i < argc; i++)
	{
		float value = std::atof(argv[i]);

		if (value <= 0)
			throw std::out_of_range("Error: input must be a positive integer");
		if (value > std::numeric_limits<int>::max())
			throw std::out_of_range("Error: input is too large");
		lst.push_back(static_cast<int>(value));
	}
	std::clock_t	lDataEnd = std::clock();
	lDataTime = (static_cast<double>(lDataEnd - lDataStart) / CLOCKS_PER_SEC) * 1e6;
	std::clock_t	vDataStart = std::clock();
	for (int i = 1; i < argc; i++)
	{
		float value = std::atof(argv[i]);

		if (value <= 0)
			throw std::out_of_range("Error: input must be a positive integer");
		if (value > std::numeric_limits<int>::max())
			throw std::out_of_range("Error: input is too large");
		vec.push_back(static_cast<int>(value));
	}
	std::clock_t	vDataEnd = std::clock();
	vDataTime = (static_cast<double>(vDataEnd - vDataStart) / CLOCKS_PER_SEC) * 1e6;
}

void	PmergeMe::sort()
{
	int size;

	if (vec.size() != lst.size())
		throw std::runtime_error("Error: parsing input");
	else
		size = vec.size();

	if (size > 1)
	{
		std::clock_t start;
		std::clock_t end;

		start = std::clock();
		vMergeInsertionSort();
		end = std::clock();
		vectorSpeed = (static_cast<double>(end - start) / CLOCKS_PER_SEC) * 1e6 + vDataTime;

		start = std::clock();
		lMergeInsertionSort();
		end = std::clock();
		listSpeed = (static_cast<double>(end - start) / CLOCKS_PER_SEC) * 1e6 + lDataTime;
	}
}

static lIterator lNext(lIterator it)
{
	return (++it);
}

static lIterator lPrev(lIterator it)
{
	return (--it);
}

static lIterator lNextX(lIterator it, int dist)
{
	std::advance(it, dist);
	return (it);
}

static lConstIterator lConstNextX(lConstIterator it, int dist)
{
	std::advance(it, dist);
	return (it);
}

void	PmergeMe::printState(const std::string& state) const
{
	std::cout << state;
	for (vConstIterator it = vec.begin(); it != vec.end(); ++it)
		std::cout << *it << " ";
	std::cout << "\n" << state;
	for (lConstIterator it = lst.begin(); it != lst.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}

void	PmergeMe::printSpeeds() const
{
	std::cout	<< "Time to process a range of " << vec.size()
					<< " elements with std::vector: "
					<< vectorSpeed << " us" << std::endl;
	std::cout	<< "Time to process a range of " << lst.size()
					<< " elements with std::list:   "
					<< listSpeed << " us" << std::endl;
}

size_t	jacobsthalNumber(size_t n)
{
	if (n == 0)
		return (0);
	if (n == 1)
		return (1);
	size_t a = 0, b = 1, result;

	for (size_t i = 2; i <= n; ++i)
	{
		result = b + 2 * a;
		a = b;
		b = result;
	}
	return (result);
}


/*----------------------------------------------------------------------------*/
/*------------------------------ Vector Container ----------------------------*/
/*----------------------------------------------------------------------------*/

void PmergeMe::vMergeInsertionSort()
{
	vect	chainA, chainB;

	// Step 1: Group the elements of X into n/2 pairs of elements
	// Step 2: Perform n/2 comparisons, to determine the larger of the two elements in each pair
	vPairElements(chainA, chainB);

	// Step 3: Recursively sort the n/2 larger elements (chainB) using the merge-insertion sort.
	vMergeInsert(0, chainB.size() - 1, chainB);

	// Step 4: Insert at the start of S the element that was paired with the smallest element of S
	vect	sorted;
	sorted.push_back(chainA[0]);
	sorted.push_back(chainB[0]);

	// Step 5: Insert the remaining n/2 - 1  using Jacobsthal Numbers for binary search.
	vInsertRemainingElements(sorted, chainA, chainB);

	vec = sorted;
}

void PmergeMe::vPairElements(vect &chainA, vect &chainB)
{
	for (size_t i = 0; i < vec.size() - 1; i += 2)
	{
		if (vec[i] < vec[i + 1])
		{
			chainA.push_back(vec[i]);
			chainB.push_back(vec[i + 1]);
		}
		else
		{
			chainA.push_back(vec[i + 1]);
			chainB.push_back(vec[i]);
		}
	}
	if (vec.size() % 2 != 0) {
		chainB.push_back(vec.back());
	}
}

void	PmergeMe::vMergeInsert(int start, int end, vect& chainB)
{
	if (start >= end)
		return;

	int mid = start + (end - start) / 2;

	vMergeInsert(start, mid, chainB);
	vMergeInsert(mid + 1, end, chainB);
	vMerge(start, mid, end, chainB);
}

void	PmergeMe::vMerge(int start, int mid, int end, vect& chainB)
{
	vect left(chainB.begin() + start, chainB.begin() + mid + 1);
	vect right(chainB.begin() + mid + 1, chainB.begin() + end + 1);

	size_t l = 0, r = 0, v = start;

	while (l < left.size() && r < right.size())
	{
		if (left[l] <= right[r])
			chainB[v++] = left[l++];
		else
			chainB[v++] = right[r++];
	}
	while (l < left.size())
		chainB[v++] = left[l++];
	while (r < right.size())
		chainB[v++] = right[r++];
}

void	PmergeMe::vInsertRemainingElements(vect &sorted, const vect &chainA, const vect &chainB)
{
	size_t jacobsthalIndex = 2;
	size_t insertedCount = 1;
	size_t nextJacobsthal = jacobsthalNumber(jacobsthalIndex);

	while (insertedCount < chainA.size())
	{
		for (size_t i = insertedCount + 1; i <= nextJacobsthal; ++i)
		{
			if (i - 1 < chainA.size())
			{
				vIterator posA = std::lower_bound(sorted.begin(), sorted.end(), chainA[i - 1]);
				sorted.insert(posA, chainA[i - 1]);
			}
			if (i - 1 < chainB.size())
			{
				vIterator posB = std::lower_bound(sorted.begin(), sorted.end(), chainB[i - 1]);
				sorted.insert(posB, chainB[i - 1]);
			}
		}
		insertedCount = nextJacobsthal;
		jacobsthalIndex++;
		nextJacobsthal = std::min(jacobsthalNumber(jacobsthalIndex), chainA.size());
	}
	for (size_t i = insertedCount; i < chainB.size(); ++i)
	{
		vIterator pos = std::lower_bound(sorted.begin(), sorted.end(), chainB[i]);
		sorted.insert(pos, chainB[i]);
	}
}

/*----------------------------------------------------------------------------*/
/*------------------------------- List Container -----------------------------*/
/*----------------------------------------------------------------------------*/

void	PmergeMe::lMergeInsertionSort()
{
	list	chainA, chainB;

	// Step 1: Group the elements of X into n/2 pairs of elements
	// Step 2: Perform n/2 comparisons, to determine the larger of the two elements in each pair
	lPairElements(chainA, chainB);

	// Step 3: Recursively sort the n/2 larger elements (chainB) using the merge-insertion sort.
	lMergeInsert(0, chainB.size() - 1, chainB);

	// Step 4: Insert at the start of S the element that was paired with the smallest element of S
	list	sorted;
	sorted.push_back(chainA.front());
    sorted.push_back(chainB.front());

	// Step 5: Insert the remaining n/2 - 1  using Jacobsthal Numbers for binary search.
	lInsertRemainingElements(sorted, chainA, chainB);

	lst = sorted;
}

void PmergeMe::lPairElements(list &chainA, list &chainB)
{
	lIterator	it = lst.begin();

	while (it != lPrev(lst.end()) && it != lst.end())
	{
		if (*it < *lNext(it))
		{
			chainA.push_back(*it);
			chainB.push_back(*lNext(it));
		}
		else
		{
			chainB.push_back(*it);
			chainA.push_back(*lNext(it));
		}
		std::advance(it, 2);
	}
	if (it == lPrev(lst.end()))
		chainB.push_back(*it);
}

void	PmergeMe::lMergeInsert(int start, int end, list& chainB)
{
	if (start == end)
		return ;

	int mid = start + (end - start) / 2;

	lMergeInsert(start, mid, chainB);
	lMergeInsert(mid + 1, end, chainB);
	lMerge(start, mid, end, chainB);
}

void	PmergeMe::lMerge(int start, int mid, int end, list& chainB)
{
	list		merged;
	lIterator	itLeft = lNextX(chainB.begin(), start);
	lIterator	itRight = lNextX(chainB.begin(), mid + 1);
	lIterator	endLeft = lNextX(chainB.begin(), mid + 1);
	lIterator	endRight = lNextX(chainB.begin(), end + 1);

	while (itLeft != endLeft && itRight != endRight)
	{
		if (*itLeft <= *itRight)
		{
			merged.push_back(*itLeft);
			itLeft++;
		}
		else
		{
			merged.push_back(*itRight);
			itRight++;
		}
	}
	while (itLeft != endLeft)
	{
		merged.push_back(*itLeft);
		itLeft++;
	}
	while (itRight != endRight)
	{
		merged.push_back(*itRight);
		itRight++;
	}
}

void PmergeMe::lInsertRemainingElements(list& sorted, const list& chainA, const list& chainB)
{
	size_t	jacobsthalIndex = 2;
	size_t	insertedCount = 1;
	size_t	nextJacobsthal = jacobsthalNumber(jacobsthalIndex);

	while (insertedCount < chainA.size() || insertedCount < chainB.size())
	{
		for (size_t i = insertedCount + 1; i <= nextJacobsthal; ++i)
		{
			if (i - 1 < chainA.size())
			{
				lConstIterator itA = lConstNextX(chainA.begin(), i - 1);
				lIterator posA = std::lower_bound(sorted.begin(), sorted.end(), *itA);
				sorted.insert(posA, *itA);
			}
			if (i - 1 < chainB.size())
			{
				lConstIterator itB = lConstNextX(chainB.begin(), i - 1);
				lIterator posB = std::lower_bound(sorted.begin(), sorted.end(), *itB);
				sorted.insert(posB, *itB);
			}
		}
		insertedCount = nextJacobsthal;
		jacobsthalIndex++;
		nextJacobsthal = std::min(jacobsthalNumber(jacobsthalIndex), std::max(chainA.size(), chainB.size()));
	}
	for (size_t i = insertedCount; i < chainB.size(); ++i)
	{
		lConstIterator itB = lConstNextX(chainB.begin(), i);
		lIterator pos = std::lower_bound(sorted.begin(), sorted.end(), *itB);
		sorted.insert(pos, *itB);
	}
}


