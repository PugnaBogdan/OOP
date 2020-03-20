#include "Validator.h"

void validateData(vector<string> vectorToValidate)
{
	string errors;
	for (auto &index : vectorToValidate[2])
		if (!isdigit(index)) {
			errors = errors + "imageClarityLevel needs to be a double\n"; break;
		}
	for (auto &index : vectorToValidate[3])
		if (!isdigit(index)) {
			errors = errors + "quantiry needs to be a double\n"; break;
		}

	if (errors.size() > 0)
		throw dataException(errors);
}
