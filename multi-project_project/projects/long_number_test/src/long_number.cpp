#include "long_number.hpp"

using biv::LongNumber;
		
LongNumber::LongNumber() {
	sign = 1;
	length = 1;
	numbers = new int[1]{0};
}

LongNumber::LongNumber(const char* const str) {
	int str_length = std::strlen(str);
	int i = 0;
	if (str[0] == '-') {
		i = 1;
		sign = -1;
		length = str_length - 1;
	} else {
		i = 0;
		sign = 1;
		length = str_length;
	}
	
	numbers = new int[length]{}; 
    for (int k = i ; k < length; k++){
		numbers[k - i] = str[k] - '0';
	}
}

LongNumber::LongNumber(const LongNumber& x) {
	sign = x.sign;
	length = x.length;
	numbers = new int[length];
	for (int i = 0; i < length; i++){
		numbers[i] = x.numbers[i];
	}
}

LongNumber::LongNumber(LongNumber&& x) {
	sign = x.sign;
	length = x.length;
	numbers = x.numbers;
	x.numbers = nullptr;
	
}

LongNumber::~LongNumber() {
	length = 0;
	delete[] numbers;
	numbers = nullptr;
}


LongNumber& LongNumber::operator = (const char* const str) {
	int str_length = std::strlen(str);
	if (str[0] == '-') {
		sign = -1;
		length = str_length - 1;
	} else {
		sign = 1;
		length = str_length;
	}
	
	delete[] numbers;
	numbers = new int[length]{}; 
    for (int i = 0; i < length; i++){
		numbers[i] = str[str_length - i - 1] - '0';
	}
	
	return *this;
}

LongNumber& LongNumber::operator = (const LongNumber& x) {
	if (this == &x) return *this;
	
	sign = x.sign;
	length = x.length;
	
	delete [] numbers;
	numbers = new int[length];
	for (int i = 0; i < length; i++){
		numbers[i] = x.numbers[i];
	}
	
	return *this;
}

LongNumber& LongNumber::operator = (LongNumber&& x) {
	sign = x.sign;
	length = x.length;
	
	delete [] numbers;
	numbers = x.numbers;
	x.numbers = nullptr;
	
	return *this;
}

bool LongNumber::operator == (const LongNumber& x) const {
	if (sign != x.sign){
		return false;
	}
	
	if (length != x.length){
		return false;
	}
	
	for (size_t i = 0; i < length; i++){
		if (numbers[i] != x.numbers[i]){
			return false;
		}
	}
	
	return true;
}

bool LongNumber::operator > (const LongNumber& x) const {
	if (sign != x.sign){
        return sign > x.sign;
	}
	
	if (length != x.length){
		 return (length > x.length) ^ (sign < 0);
	}
	
	for (size_t i = 0; i < length; i++){
        if (numbers[i] != x.numbers[i]){
            return (numbers[i] > x.numbers[i]) ^ (sign < 0);
		}
	}
	return false;
}

bool LongNumber::operator < (const LongNumber& x) const {
	return !(*this > x || *this == x);
}

bool LongNumber::operator != (const LongNumber& x) const {
	return !(*this == x);
}

LongNumber LongNumber::operator - () const {
    LongNumber res; 
    res.sign = -sign; 
    res.length = length;
    res.numbers = numbers;

    return res; 
}

LongNumber LongNumber::operator + (const LongNumber& x) const {
	if (sign != x.sign) {
        if (sign == -1) {
            return x - (-(*this)); 
        } else {
            return *this - (-x);    
        }
    }
	

	long maxLen = std::max(length, x.length);
	
	int* numbers1 = new int[maxLen]{};  
	int* numbers2 = new int[maxLen]{};

	for (size_t i = 0; i < length; ++i) {
		numbers1[maxLen - length + i] = numbers[i];
	}
	for (size_t i = 0; i < x.length; ++i) {
		numbers2[maxLen - x.length + i] = x.numbers[i];
	}
	
	LongNumber res;
	res.sign = sign;
	size_t len = maxLen + 1;
	res.length = len;
	res.numbers = new int[len]{};
	
	for (size_t l = 0; l < maxLen; l++){
		res.numbers[l + 1] = numbers1[l] + numbers2[l];
	}
	
	for (size_t l = len - 1; l > 0; l--){
		res.numbers[l - 1] += res.numbers[l] / 10;
		res.numbers[l] %= 10;
	}
	
	
	if (res.numbers[0] == 0){
		LongNumber res2;
		res2.sign = sign;
		res2.length = maxLen;
		res2.numbers = new int[maxLen]{};
		for (size_t l = 0; l < len - 1; l++){
			res2.numbers[l] = res.numbers[l + 1];
		}
		
		delete[] res.numbers;
		delete[] numbers1;
		delete[] numbers2;
		
		return res2;
	}
	
	delete[] numbers1;
	delete[] numbers2;
	
	return res;
	
}

LongNumber LongNumber::operator - (const LongNumber& x) const {
	if (sign == 1 && x.sign == 1){
		long maxLen = std::max(length, x.length);
		
		//adding zeros to the beginning of 1 array
		int* numbers1;
		int i = 0;
		while (length + i != maxLen){
			numbers1 = new int[i + length]{};
			i++;
		}
		for (size_t j = i; j < length + i; j++){
			numbers1[j] = numbers[j - i];
		}
		
		//adding zeros to the beginning of 2 array
		int* numbers2;
		i = 0;
		while (x.length + i != maxLen){
			numbers2 = new int[i + x.length]{};
			i++;
		}
		for (size_t j = i; j < x.length + i; j++){
			numbers2[j] = x.numbers[j - i];
		}
		
		bool flag;
		if (*this > x || *this == x){
			flag = true;
		} else {
			flag = false;
		}
		
		LongNumber res;
		if (flag){
			res.sign = 1;
		} else {
			res.sign = -1;
		}
		size_t len = maxLen + 1;
		res.length = len;
		res.numbers = new int[len]{};
		
		for (size_t l = 0; l < len; l++){
			if (flag){
				res.numbers[l + 1] = numbers1[l] - numbers2[l];
			} else {
				res.numbers[l + 1] = numbers2[l] - numbers1[l];
			}
		}
		
		for (size_t l = len - 1; l > 0; l--){
			if (res.numbers[l] < 0) {
				res.numbers[l] += 10;
				res.numbers[l - 1]--;
			}
		}
		
		int p = 0;
		while (res.numbers[p] == 0){
			p++;
		}
		if (p != 0){
			LongNumber res2;
			res2.sign = res.sign;
			res2.length = len - p;
			res2.numbers = new int[len - p]{};
			for (size_t l = 0; l < len - p; l++){
				res2.numbers[l] = res.numbers[l + p];
			}
			return res2;
		}
		return res;
		
		
	} else if(sign == -1 && x.sign == -1){
		return (-x) - (-(*this));
	} else {
		return *this + (-x);
	}
}

LongNumber LongNumber::operator * (const LongNumber& x) const {
	size_t len = length + x.length;
	
	LongNumber res;
	res.sign = sign * x.sign;
	res.length = len;
	res.numbers = new int[len]{};
	
	for (size_t i = 0; i < length; i++){
        for (size_t j = 0; j < x.length; j++){
            res.numbers[i + j + 1] += numbers[i] * x.numbers[j];
		}
	}
	for (size_t i = len - 1; i > 0; i--) {
        res.numbers[i - 1] += res.numbers[i] / 10; 
        res.numbers[i] %= 10; 
    }
	
	int p = 0;
	for (size_t i = 0; i < res.length; i++){
		if (res.numbers[i] == 0 && p == 0){
			continue;
		} else {
			p = i + 1;
			break;
		}
	}
	
	if (p != 0){
		LongNumber res2;
		res2.sign = res.sign;
		res2.length = len - p;
		res2.numbers = new int[len - p]{};
		for (size_t l = 0; l < len - p; l++){
			res2.numbers[l] = res.numbers[l + p];
		}
		return res2;
	}
	return res;
}

LongNumber LongNumber::operator / (const LongNumber& x) const {
	LongNumber res;
	res.sign = sign * x.sign;
	int i = 0;
	if (sign == 1){
		i = 0;
	} else {
		i = 1;
	}
	int j = 0;
	if (x.sign == 1){
		j = 0;
	} else {
		j = 1;
	}
	
	LongNumber dividend;
	dividend.sign = sign;
	dividend.length = length - i;
	dividend.numbers = new int[length - i]{};
	
	LongNumber divisor;
	divisor.sign = x.sign;
	divisor.length = length - j;
	divisor.numbers = new int[length - j]{};
	/*
    for (int k = i; k < length; k++){
		dividend[k - i] = numbers[k];
	}
	LongNumber divisor[length - j];
    for (int k = j; k < length; k++){
		divisor[k - j] = numbers[k];
	}
	*/
	
	if (*this == LongNumber(0)) {
        return LongNumber("0");
    }
	if (dividend < divisor) {
        return LongNumber("0");
    }
	if (dividend == divisor) {
		 if (res.sign == 1){
			return LongNumber("1");
		 } else {
			return LongNumber("-1");
		 }
		
    }
	
    LongNumber current(0);
	int count = 0;
	for (int k = i; k < dividend.length; k++){
		
		std::string el = std::to_string(dividend.numbers[k]);
		const char* c_el = el.c_str();
		
		current = current * LongNumber("10") + LongNumber(c_el);
		
		int res_number = 0;
		while (current > divisor || current == divisor) {
			current = current - divisor;
			res_number++;
		}
		if (res_number != 0){
			count++;
		}
		res.numbers[count] = res_number;
	}
	/*
	int el = 0;
	while (res_numbers[el] != 0){
		res.numbers[el] = res_numbers[el];
		el++;
	}
	
	
	while (res.numbers.size() > 1 && res.numbers.begin() == 0) {
		res.numbers.erase(res.numbers.begin());
    }
	*/
	return res;
}

LongNumber LongNumber::operator % (const LongNumber& x) const {
	LongNumber res;
	res.sign = sign * x.sign;
	int i = 0;
	if (sign == 1){
		i = 0;
	} else {
		i = 1;
	}
	int j = 0;
	if (x.sign == 1){
		j = 0;
	} else {
		j = 1;
	}
	
	LongNumber dividend;
	dividend.sign = sign;
	dividend.length = length - i;
	dividend.numbers = new int[length - i]{};
	
	LongNumber divisor;
	divisor.sign = x.sign;
	divisor.length = length - j;
	divisor.numbers = new int[length - j]{};
	/*
    for (int k = i; k < length; k++){
		dividend[k - i] = numbers[k];
	}
	LongNumber divisor[length - j];
    for (int k = j; k < length; k++){
		divisor[k - j] = numbers[k];
	}
	*/
	
	if (*this == LongNumber(0)) {
        return LongNumber("0");
    }
	if (dividend < divisor) {
        return LongNumber("0");
    }
	if (dividend == divisor) {
		 if (res.sign == 1){
			return LongNumber("1");
		 } else {
			return LongNumber("-1");
		 }
		
    }
	
    LongNumber current(0);
	for (int k = i; k < dividend.length; k++){
		
		std::string el = std::to_string(dividend.numbers[k]);
		const char* c_el = el.c_str();
		
		current = current * LongNumber("10") + LongNumber(c_el);
		
		while (current > divisor || current == divisor) {
			current = current - divisor;
		}
	}
	return current;
}

int LongNumber::get_digits_number() const noexcept {
	return length;
}

int LongNumber::get_rank_number(int rank) const {
	return numbers[rank];
}

bool LongNumber::is_negative() const noexcept {
	if (sign == 1){
		return true;
	} else { 
		return false;
	}
}

// ----------------------------------------------------------
// PRIVATE
// ----------------------------------------------------------
int LongNumber::get_length(const char* const str) const noexcept {
	int str_length = std::strlen(str);
	if (str[0] == '-') {
		return str_length - 1;
	} else {
		return str_length;
	}
	
}

// ----------------------------------------------------------
// FRIENDLY
// ----------------------------------------------------------
namespace biv {
	std::ostream& operator << (std::ostream &os, const LongNumber& x) {
		if (x.sign == -1){
			os << '-';
		}
		
		for (auto it = x.numbers[0]; it != x.numbers[x.length - 1]; ++it) {
			os << it;
		}
		
			
		return os;
	}
}