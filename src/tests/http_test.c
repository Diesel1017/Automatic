/*
 * main.c*
 *
 *
 *  Created on: Oct 16, 2008
 *      Author: aurich
 */

#include <assert.h>

#include "output.h"
#include "utils.h"
#include "web.h"

int8_t verbose = P_NONE;

void testGetHTTP(void) {
	int ret = 1;
	WebData *data = NULL;


	//test invalid URL
	data = getHTTPData(NULL);
	assert(data == NULL);

	//test invalid URL 2
	data = getHTTPData("http://thisurldoesntexist.co.ge");
	assert(data);
	assert(data->responseCode != 200);
	assert(data->response->data == NULL);
	WebData_free(data);

	//test HTTP URL
	data = getHTTPData("http://www.binsearch.info/?action=nzb&33455941=1");
	assert(data && data->response);
	WebData_free(data);
}

int main(void) {
	testGetHTTP();
	return 0;
}
