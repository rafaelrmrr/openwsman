/*******************************************************************************
* Copyright (C) 2004-2006 Intel Corp. All rights reserved.
*
* Redistribution and use in source and binary forms, with or without
* modification, are permitted provided that the following conditions are met:
*
*  - Redistributions of source code must retain the above copyright notice,
*    this list of conditions and the following disclaimer.
*
*  - Redistributions in binary form must reproduce the above copyright notice,
*    this list of conditions and the following disclaimer in the documentation
*    and/or other materials provided with the distribution.
*
*  - Neither the name of Intel Corp. nor the names of its
*    contributors may be used to endorse or promote products derived from this
*    software without specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ``AS IS''
* AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
* IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
* ARE DISCLAIMED. IN NO EVENT SHALL Intel Corp. OR THE CONTRIBUTORS
* BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
* CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
* SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
* INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
* CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
* ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
* POSSIBILITY OF SUCH DAMAGE.
*******************************************************************************/

/**
 * @author Anas Nashif
 */

#ifndef WSMAN_SOAP_ENVELOPE_H_
#define WSMAN_SOAP_ENVELOPE_H_


#define ENFORCE_MUST_UNDERSTAND	"EnforceMustUnderstand"

void wsman_is_valid_envelope(WsmanMessage *msg, WsXmlDocH doc);
int wsman_is_duplicate_message_id (SOAP_FW* fw, WsXmlDocH doc);
char* get_soap_header_value(SOAP_FW* fw, WsXmlDocH doc, char* nsUri, char* name);
WsXmlNodeH get_soap_header_element(SOAP_FW* fw, 
        WsXmlDocH doc, char* nsUri, char* name);
WsXmlDocH build_soap_fault(SOAP_FW *fw, char *soapNsUri, char *faultNsUri, char *code, char *subCode, char *reason, char *detail);
void build_soap_version_fault(SOAP_FW *fw);

WsXmlDocH ws_create_response_envelope(WsContextH cntx, 
        WsXmlDocH rqstDoc, 
        char* action);
WsXmlDocH wsman_build_envelope(WsContextH cntx, char* action, char* replyToUri, char* systemUri, char* resourceUri,
        char* toUri, actionOptions options);
WsXmlDocH wsman_build_inbound_envelope(SOAP_FW* fw, WsmanMessage *msg);


#endif
