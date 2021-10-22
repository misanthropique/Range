/**
 * Copyright ©2021. Brent Weichel. All Rights Reserved.
 * Permission to use, copy, modify, and/or distribute this software, in whole
 * or part by any means, without express prior written agreement is prohibited.
 */
#pragma once

#include <cstddef>
#include <iterator>
#include <type_traits>
#include <utility>

/**
 * 
 */
template < typename IntegralType,
	typename = typename std::enable_if< std::is_integral< IntegralType >::value >::type >
class Range
{
	IntegralType mStartValue;  ///< Start value of the range (inclusive)
	IntegralType mStopValue;   ///< Stop value of the range  (exclusive)
	IntegralType mStepValue;   ///< Step taken on each increment.

public:
	class iterator
	{
		IntegralType mCurrent;
		IntegralType mStep;

	public:
		using iterator_category = std::forward_iterator_tag;
		using difference_type   = std::ptrdiff_t;
		using value_type        = IntegralType;
		using pointer           = IntegralType*;
		using reference         = IntegralType&;

		iterator( iterator&& other )
		{
			
		}

		iterator( const iterator& other );
		iterator( IntegralType currentValue, IntegralValue step );

		bool operator==( const iterator& other ) const
		{
			
		}

		bool operator!=( const iterator& other ) const
		{
			return not this->operator==( other );
		}

		/**
		 * Dereference operator.
		 * @return Const reference to the integral value.
		 */
		const reference operator*()
		{
			return mCurrent;
		}

		/**
		 * Post increment.
		 * @return Iterator to the previous iterator value.
		 */
		iterator operator++( int )
		{
			iterator previous( *this );
			this->operator++();
			return previous;
		}

		/**
		 * Pre increment.
		 * @return Reference to this iterator instance.
		 */
		iterator& operator++()
		{
			
		}

		void swap( iterator& other )
		{
			
		}
	};

	/**
	 * Default constructor for an empty range.
	 */
	Range()
	{
		mStartValue = 0;
		mStopValue = 0;
		mStepValue = 0;
	}

	/**
	 * Move constructor.
	 * @param other R-Value of the Range to move to this instance.
	 */
	Range( Range&& other )
	{
		mStartValue = std::exchange( other.mStartValue, 0 );
		mStopValue = std::exchange( other.mStopValue, 0 );
		mStepValue = std::exchange( other.mStepValue, 0 );
	}

	/**
	 * Copy constructor.
	 * @param other Const reference to the Range to copy.
	 */
	Range( const Range& other )
	{
		mStartValue = other.mStartValue;
		mStopValue = other.mStopValue;
		mStepValue = other.mStepValue;
	}

	// Valid (h,s];i | h < s
	// Valid [s,h);i | s < h
	// Valid (h,s];i or [s,h);i | where h = s
	//

	/**
	 * If stop is greater than zero, then the range shall be: [0, stop); step
	 * If IntegralType is signed and stop is less than zero, then the range shall be: (stop, 0]; step
	 * 
	 */
	Range( IntegralType stopValue, IntegralType step = 1 )
	{
		mStartValue = 0;
		mStopValue = stopValue;
		mStepValue = step;
	}

	Range( IntegralType startValue, IntegralType stopValue, IntegralType step = 1 );
	Range( std::pair< IntegralType, IntegralType > range, IntegralType step = 1 );

	/**
	 * Iterator to the beginning of the range.
	 * @return Iterator to the beginning of the range.
	 */
	iterator begin() const
	{
		return iterator( mStartValue, mStepValue );
	}

	/**
	 * Iterator to the end of the range.
	 * @return Iterator to the end of the range.
	 */
	iterator end() const
	{
		return iterator( mStopValue, mStepValue );
	}

	/**
	 * Value for the start of the range.
	 * @return The start of the range is returned.
	 */
	IntegralType start() const
	{
		return mStartValue;
	}

	/**
	 * Value for the end of the range.
	 * @return The end of the range is returned.
	 */
	IntegralType stop() const
	{
		return mStopValue;
	}
};
