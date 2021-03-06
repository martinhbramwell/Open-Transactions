/*************************************************************
 *    
 *  OTAssetContract.cpp
 *  
 */

/************************************************************
 -----BEGIN PGP SIGNED MESSAGE-----
 Hash: SHA256
 
 *                 OPEN TRANSACTIONS
 *
 *       Financial Cryptography and Digital Cash
 *       Library, Protocol, API, Server, and GUI 
 *    
 *    	 -- Anonymous Numbered Accounts.
 *    	 -- Untraceable Digital Cash.
 *    	 -- Triple-Signed Receipts.
 *    	 -- Cheques, Vouchers, Transfers, Inboxes.
 *    	 -- Basket Currencies, Markets, Payment Plans.
 *    	 -- Signed, XML, Ricardian-style Contracts.
 *    
 *  Copyright (C) 2010-2012 by "Fellow Traveler" (A pseudonym)
 *
 *  EMAIL:
 *  FellowTraveler@rayservers.net
 *  
 *  BITCOIN:  1NtTPVVjDsUfDWybS4BwvHpG2pdS9RnYyQ
 *
 *  KEY FINGERPRINT (PGP Key in license file):
 *  9DD5 90EB 9292 4B48 0484  7910 0308 00ED F951 BB8E
 *
 *  OFFICIAL PROJECT WIKI(s):
 *  https://github.com/FellowTraveler/Moneychanger
 *  https://github.com/FellowTraveler/Open-Transactions/wiki 
 *
 *  WEBSITE:
 *  http://www.OpenTransactions.org/
 *    
 *  Components and licensing:
 *   -- Moneychanger..A Java client GUI.....LICENSE:.....GPLv3
 *   -- OTLib.........A class library.......LICENSE:...LAGPLv3 
 *   -- OT-API........A client API..........LICENSE:...LAGPLv3
 *   -- testwallet....Command-line client...LICENSE:...LAGPLv3
 *   -- OT-Server.....Server Application....LICENSE:....AGPLv3
 *  Github.com/FellowTraveler/Open-Transactions/wiki/Components
 *
 *  All of the above OT components were designed and written by
 *  Fellow Traveler, with the exception of Moneychanger, which
 *  was contracted out to Vicky C (livewire_3001@yahoo.com).
 *
 *  -----------------------------------------------------
 *
 *   LICENSE:
 *   This program is free software: you can redistribute it
 *   and/or modify it under the terms of the GNU Affero
 *   General Public License as published by the Free Software
 *   Foundation, either version 3 of the License, or (at your
 *   option) any later version.
 *    
 *   ADDITIONAL PERMISSION under the GNU Affero GPL version 3
 *   section 7: (This paragraph applies only to the LAGPLv3
 *   components listed above.) If you modify this Program, or
 *   any covered work, by linking or combining it with other
 *   code, such other code is not for that reason alone subject
 *   to any of the requirements of the GNU Affero GPL version 3.
 *   (==> This means if you are only using the OT-API, then you
 *   don't have to open-source your code--only your changes to
 *   Open Transactions itself must be open source. Similar to
 *   LGPLv3, except it applies to software-as-a-service, not
 *   just to distributing binaries.)
 *
 *   Extra WAIVER for OpenSSL, Lucre, and all other libraries
 *   used by Open Transactions: This program is released under
 *   the AGPL with the additional exemption that compiling,
 *   linking, and/or using OpenSSL is allowed. The same is true
 *   for any other open source libraries included in this
 *   project: complete waiver from the AGPL is hereby granted to
 *   compile, link, and/or use them with Open Transactions,
 *   according to their own terms, as long as the rest of the
 *   Open Transactions terms remain respected, with regard to
 *   the Open Transactions code itself.
 *    
 *   Lucre License:
 *   This code is also "dual-license", meaning that Ben Lau-
 *   rie's license must also be included and respected, since
 *   the code for Lucre is also included with Open Transactions.
 *   See Open-Transactions/OTLib/Lucre/LUCRE_LICENSE.txt
 *   The Laurie requirements are light, but if there is any
 *   problem with his license, simply remove the Lucre code.
 *   Although there are no other blind token algorithms in Open
 *   Transactions (yet. credlib is coming), the other functions
 *   will continue to operate.
 *   -----------------------------------------------------
 *   You should have received a copy of the GNU Affero General
 *   Public License along with this program.  If not, see:
 *   http://www.gnu.org/licenses/
 *
 *   If you would like to use this software outside of the free
 *   software license, please contact FellowTraveler.
 *   (Unfortunately many will run anonymously and untraceably,
 *   so who could really stop them?)
 *   
 *   DISCLAIMER:
 *   This program is distributed in the hope that it will be
 *   useful, but WITHOUT ANY WARRANTY; without even the implied
 *   warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
 *   PURPOSE.  See the GNU Affero General Public License for
 *   more details.
 -----BEGIN PGP SIGNATURE-----
 Version: GnuPG v1.4.11 (Darwin)
 
 iQIcBAEBCAAGBQJOjvvUAAoJEAMIAO35UbuOBlMP/1LX0xJ9CrTOe1G/mgc+VygT
 JPVZDAbQDL/lJXOZMbaPJ/GaLXyEnTViHp97ERrlVuBQz+9uonIKCmPqAGYGVBG1
 MGV2QcscXU2aOUT1VPf2OYEOIul0h8FX2lixfqouH9/OkVsGRLr79Zu8z3zdsO4R
 ktQtjZEU6lnL2t6cmp/cuXlQnbz1xvxd56xNDR11YP07Z4x+CuDB4EAK+P9TfCwn
 tqq5yJmxJM9HtMoi3cUU7kXodKm1n1YZt7O46DOxHqbXqErHChN1ekSK0fXad614
 Gmh+5JfvHjx5XoFWMxb46aAAcUiG8+QpFBcKtSYP2X96k1ylgxMCzrK60ec/MxKV
 BzvP00OJ6PzzrTlcUaCgJ8ZX+0scOMvW0XKioEorozKSWNFvT4Drc4Thhy8u9ET3
 ru1enNFrjdxKjw2+ZTQcKSZjSRx2kMQ2od/dkqUlhe/M1cHGhseH6ls7pItrkykE
 ufZ9GlZoxYE+FRatIBPneT9WwsvFFvH+i6cQ/MM9pbTr19g6VPzVZ4U9E65BbTDB
 czITynH+uMtJLbprtCdQlsI+vqTgYNoY8AUsmnr1qUkp020qGlvwfCJVrooisTmm
 yIh+Yp/KBzySU3inzclaAfv102/t5xi1l+GTyWHiwZxlyt5PBVglKWx/Ust9CIvN
 6h9BYZFTZrh/OwBXCdAv
 =MUfS
 -----END PGP SIGNATURE-----
 **************************************************************/


#include <cstring>


#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "irrxml/irrXML.h"

using namespace irr;
using namespace io;

#include "OTStorage.h"

#include "OTAssetContract.h"
#include "OTStringXML.h"
#include "OTPseudonym.h"
#include "OTBasket.h"
#include "OTLog.h"



OTAssetContract::OTAssetContract() : OTContract()
{
	
}

OTAssetContract::OTAssetContract(OTString & name, OTString & foldername, OTString & filename, OTString & strID) 
: OTContract(name, foldername, filename, strID)
{

}


OTAssetContract::~OTAssetContract()
{
	// OTContract::~OTContract is called here automatically, and it calls Release.
	// So I don't need to call it here again when it's already called by the parent.
}

// Make sure you escape any lines that begin with dashes using "- "
// So "---BEGIN " at the beginning of a line would change to: "- ---BEGIN"
// This function expects that's already been done.
// This function assumes there is only unsigned contents, and not a signed contract.
// This function is intended to PRODUCE said signed contract.
//
bool OTAssetContract::CreateContract(OTString & strContract, OTPseudonym & theSigner)
{	
	Release();
	
	m_xmlUnsigned = strContract;
	
	// This function assumes that m_xmlUnsigned is ready to be processed.
	// This function only processes that portion of the contract.
	bool bLoaded = LoadContractXML();
	
	if (bLoaded)
	{
		OTString strTemp;
		
		SignContract(theSigner);
		RewriteContract(strTemp); // this trims
		
		// This is probably redundant...
//		std::string str_Trim(strTemp.Get());
//		std::string str_Trim2 = OTString::trim(str_Trim);
//		strTemp.Set(str_Trim2.c_str());
		// -----------------------------------
		Release();
		LoadContractFromString(strTemp);
		SaveContract();
		
		// -----------------------------------
		
		OTIdentifier NEW_ID;
		CalculateContractID(NEW_ID);
		m_ID = NEW_ID;	
		
		return true;
	}	
	
	return false;
}


// Normally, Asset Contracts do NOT update / rewrite their contents, since their
// primary goal is for the signature to continue to verify.  But when first creating
// a basket contract, we have to rewrite the contents, which is done here.
bool OTAssetContract::CreateBasket(OTBasket & theBasket, OTPseudonym & theSigner)
{
	Release();

	// Grab a string copy of the basket information.
	theBasket.SaveContractRaw(m_strBasketInfo);
	
	// -------------------------------
	
	// Insert the server's public key as the "contract" key for this basket currency.
	OTString strPubKey, strKeyName("contract"); // todo stop hardcoding
	theSigner.GetPublicKey().GetPublicKey(strPubKey);
	
	InsertNym(strKeyName, strPubKey);

	// todo check the above two return values.
	
	OTASCIIArmor theBasketArmor(m_strBasketInfo);
	
	// -------------------------------
	
	m_xmlUnsigned.Concatenate("<?xml version=\"%s\"?>\n\n", "1.0");		
	
	m_xmlUnsigned.Concatenate("<basketContract version=\"%s\">\n\n", m_strVersion.Get());
	m_xmlUnsigned.Concatenate("<basketInfo>\n%s</basketInfo>\n\n", theBasketArmor.Get());
	m_xmlUnsigned.Concatenate("<key name=\"%s\">\n%s</key>\n\n", strKeyName.Get(), strPubKey.Get());

	m_xmlUnsigned.Concatenate("</basketContract>\n");		
	

	// This function assumes that m_xmlUnsigned is ready to be processed.
	// This function only processes that portion of the contract.
	bool bLoaded = LoadContractXML();
	
	if (bLoaded)
	{
		OTString strTemp;

		SignContract(theSigner);
		RewriteContract(strTemp); // this trims

		// This is probably redundant...
//		std::string str_Trim(strTemp.Get());
//		std::string str_Trim2 = OTString::trim(str_Trim);
//		strTemp.Set(str_Trim2.c_str());
		// -----------------------------------
		Release();
		
		LoadContractFromString(strTemp);
		SaveContract();
		
		OTIdentifier NEW_ID;
		CalculateContractID(NEW_ID);
		m_ID = NEW_ID;	
		
		return true;
	}	
	
	return false;
	
}

	
bool OTAssetContract::DisplayStatistics(OTString & strContents) const
{
	const OTString strID(m_ID);
	
	strContents.Concatenate(
							" Asset Type:  %s\n"
							" AssetTypeID: %s\n"
							"\n",
							m_strName.Get(),
							strID.Get());
	return true;
}


bool OTAssetContract::SaveContractWallet(OTString & strContents) const
{
	const OTString strID(m_ID);
	
	OTASCIIArmor ascName;
	
	if (m_strName.Exists()) // name is in the clear in memory, and base64 in storage.
	{
		ascName.SetString(m_strName, false); // linebreaks == false
	}
	
	strContents.Concatenate("<assetType name=\"%s\"\n"
							" assetTypeID=\"%s\" />\n\n",
							m_strName.Exists() ? ascName.Get() : "",
							strID.Get());
	
	return true;
}


bool OTAssetContract::SaveContractWallet(std::ofstream & ofs)
{
	OTString strOutput;
	
	if (SaveContractWallet(strOutput))
	{
		ofs << strOutput.Get();
		return true;
	}
	
	return false;
}



/*
bool OTAssetContract::SaveContractWallet(FILE * fl)
{
	OTString strID(m_ID);
	
	fprintf(fl, "<assetType name=\"%s\"\n assetTypeID=\"%s\"\n contract=\"%s\" /> "
			"\n\n", m_strName.Get(), strID.Get(), m_strFilename.Get());	
	
	return true;
}
*/

// return -1 if error, 0 if nothing, and 1 if the node was processed.
int OTAssetContract::ProcessXMLNode(IrrXMLReader*& xml)
{
	int nReturnVal = OTContract::ProcessXMLNode(xml);

	// Here we call the parent class first.
	// If the node is found there, or there is some error,
	// then we just return either way.  But if it comes back
	// as '0', then nothing happened, and we'll continue executing.
	//
	// -- Note you can choose not to call the parent if
	// you don't want to use any of those xml tags.
	
	if (nReturnVal == 1 || nReturnVal == (-1))
		return nReturnVal;
	
	if (!strcmp("digitalAssetContract", xml->getNodeName()))
	{
		m_strVersion = xml->getAttributeValue("version");					
		
		OTLog::vOutput(1, "\n"
				"===> Loading XML portion of asset contract into memory structures...\n\n"
				"Digital Asset Contract: %s\nContract version: %s\n----------\n", m_strName.Get(), m_strVersion.Get());
		nReturnVal = 1;
	}
	else if (!strcmp("basketContract", xml->getNodeName()))
	{
		m_strVersion = xml->getAttributeValue("version");					
		
		OTLog::vOutput(1, "\n"
				"===> Loading XML portion of basket contract into memory structures...\n\n"
				"Digital Basket Contract: %s\nContract version: %s\n----------\n", m_strName.Get(), m_strVersion.Get());
		nReturnVal = 1;
	}
	
	else if (!strcmp("basketInfo", xml->getNodeName())) 
	{		
		if (false == OTContract::LoadEncodedTextField(xml, m_strBasketInfo))
		{
			OTLog::Error("Error in OTAssetContract::ProcessXMLNode: basketInfo field without value.\n");
			return (-1); // error condition
		}
		
		return 1;
	}
	
	else if (!strcmp("issue", xml->getNodeName()))
	{
		m_strIssueCompany = xml->getAttributeValue("company");
		m_strIssueEmail = xml->getAttributeValue("email");
		m_strIssueContractURL = xml->getAttributeValue("contractUrl");
		m_strIssueType = xml->getAttributeValue("type");
		
		OTLog::vOutput(2, "Loaded Issue company: %s\nEmail: %s\nContractURL: %s\nType: %s\n----------\n",
				m_strIssueCompany.Get(), m_strIssueEmail.Get(), m_strIssueContractURL.Get(),
				m_strIssueType.Get());
		nReturnVal = 1;
	}
	else if (!strcmp("currency", xml->getNodeName()) || !strcmp("shares", xml->getNodeName())) 
	{
		m_strName			= xml->getAttributeValue("name");
		m_strCurrencyName	= xml->getAttributeValue("name");
		
		m_strCurrencyTLA = xml->getAttributeValue("tla");
		m_strCurrencySymbol = xml->getAttributeValue("symbol");
		m_strCurrencyType = xml->getAttributeValue("type");
		m_strCurrencyFactor = xml->getAttributeValue("factor");
		m_strCurrencyDecimalPower = xml->getAttributeValue("decimal_power");
		m_strCurrencyFraction = xml->getAttributeValue("fraction");
		
		OTLog::vOutput(2, "Loaded Currency, Name: %s, TLA: %s, Symbol: %s\n"
				"Type: %s, Factor: %s, Decimal Power: %s, Fraction: %s\n----------\n", 
				m_strCurrencyName.Get(), m_strCurrencyTLA.Get(), m_strCurrencySymbol.Get(),
				m_strCurrencyType.Get(), m_strCurrencyFactor.Get(), m_strCurrencyDecimalPower.Get(),
				m_strCurrencyFraction.Get());
		nReturnVal = 1;
	}
	
	return nReturnVal;
}














































