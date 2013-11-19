#ifndef _MSceneMessage
#define _MSceneMessage
//
//-
// ==========================================================================
// Copyright (C) 1995 - 2006 Autodesk, Inc., and/or its licensors.  All 
// rights reserved.
// 
// The coded instructions, statements, computer programs, and/or related 
// material (collectively the "Data") in these files contain unpublished 
// information proprietary to Autodesk, Inc. ("Autodesk") and/or its 
// licensors,  which is protected by U.S. and Canadian federal copyright law 
// and by international treaties.
// 
// The Data may not be disclosed or distributed to third parties or be 
// copied or duplicated, in whole or in part, without the prior written 
// consent of Autodesk.
// 
// The copyright notices in the Software and this entire statement, 
// including the above license grant, this restriction and the following 
// disclaimer, must be included in all copies of the Software, in whole 
// or in part, and all derivative works of the Software, unless such copies 
// or derivative works are solely in the form of machine-executable object 
// code generated by a source language processor.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND. 
// AUTODESK DOES NOT MAKE AND HEREBY DISCLAIMS ANY EXPRESS OR IMPLIED 
// WARRANTIES INCLUDING, BUT NOT LIMITED TO, THE WARRANTIES OF 
// NON-INFRINGEMENT, MERCHANTABILITY OR FITNESS FOR A PARTICULAR PURPOSE, 
// OR ARISING FROM A COURSE OF DEALING, USAGE, OR TRADE PRACTICE. IN NO 
// EVENT WILL AUTODESK AND/OR ITS LICENSORS BE LIABLE FOR ANY LOST 
// REVENUES, DATA, OR PROFITS, OR SPECIAL, DIRECT, INDIRECT, OR 
// CONSEQUENTIAL DAMAGES, EVEN IF AUTODESK AND/OR ITS LICENSORS HAS 
// BEEN ADVISED OF THE POSSIBILITY OR PROBABILITY OF SUCH DAMAGES. 
// ==========================================================================
//+
//
// CLASS:    MSceneMessage
//
// *****************************************************************************
//
// CLASS DESCRIPTION (MSceneMessage)
//
// This class is used to register callbacks for scene related messages.
//
// The addCallback method registers a function that will be executed
// whenever the specified message occurs. An id is returned and is used
// to remove the callback.
//
// To remove a callback use MMessage::removeCallback.
// All callbacks that are registered by a plug-in must be removed by that
// plug-in when it is unloaded. Failure to do so will result in a fatal error.
//
// *****************************************************************************

#if defined __cplusplus

// *****************************************************************************

// INCLUDED HEADER FILES


#include <maya/MMessage.h>

class MFileObject;

// *****************************************************************************

// DECLARATIONS

// *****************************************************************************

// CLASS DECLARATION (MSceneMessage)

/// Scene messages
/**
*/
#ifdef _WIN32
#pragma warning(disable: 4522)
#endif // _WIN32

class OPENMAYA_EXPORT MSceneMessage : public MMessage
{
public:
	///
	enum Message {
		/// called after any operation that changes which files are loaded
		kSceneUpdate,
		/// called before a File > New operation
		kBeforeNew,
		/// called after a File > New operation
		kAfterNew,
		/// called before a File > Import operation
		kBeforeImport,
		/// called after a File > Import operation
		kAfterImport,
		/// called before a File > Open operation
		kBeforeOpen,
		/// called after a File > Open operation
		kAfterOpen,
		/// called before a File > Export operation
		kBeforeExport,
		/// called after a File > Export operation
		kAfterExport,
		/// called before a File > Save (or SaveAs)  operation
		kBeforeSave,
		/// called after a File > Save (or SaveAs)  operation
		kAfterSave,
        /// called before a File > Reference operation
        kBeforeReference,
        /// called after a File > Reference operation
        kAfterReference,
        /// called before a File > RemoveReference operation
        kBeforeRemoveReference,
        /// called after a File > RemoveReference operation
        kAfterRemoveReference,
		/// called before a File > ImportReference operation
		kBeforeImportReference,
		/// called after a File > ImportReference operation
		kAfterImportReference,
		/// called before a File > ExportReference operation
		kBeforeExportReference,
		/// called after a File > ExportReference operation
		kAfterExportReference,
		/// called before a File > UnloadReference operation
		kBeforeUnloadReference,
		/// called after a File > UnloadReference operation
		kAfterUnloadReference,

		/// called before a Software Render begins
		kBeforeSoftwareRender,
		/// called after a Software Render ends
		kAfterSoftwareRender,
		/// called before each frame of a Software Render
		kBeforeSoftwareFrameRender,
		/// called after each frame of a Software Render
		kAfterSoftwareFrameRender,
		/// called when an interactive render is interrupted by the user
		kSoftwareRenderInterrupted,

		/// called on interactive or batch startup after initialization
		kMayaInitialized,
		/// called just before Maya exits
		kMayaExiting,

		/// called prior to File > New operation, allows user to cancel action 
		kBeforeNewCheck,		
		/// called prior to File > Open operation, allows user to cancel action 
		kBeforeOpenCheck,
		/// called prior to File > Save operation, allows user to cancel action 
		kBeforeSaveCheck,
		/// called prior to File > Import operation, allows user to cancel action 
		kBeforeImportCheck,
		/// called prior to File > Export operation, allows user to cancel action 
		kBeforeExportCheck,
		
		/// called before a File > LoadReference operation
		kBeforeLoadReference,
		/// called after a File > LoadReference operation
		kAfterLoadReference,
		/// called before a File > LoadReference operation, allows user to cancel action
		kBeforeLoadReferenceCheck,
		/// called prior to a File > CreateReference operation, allows user to cancel action
		kBeforeReferenceCheck,

		/// last value of the enum
		kLast
   };

public:
	// Since there is no data associated with scene messages there
	// is a single "addCallback" function for all message types.
	//
	///
	static MCallbackId	addCallback( Message, void (*func)( void* clientData ),
									 void * clientData = NULL,
									 MStatus * ReturnStatus = NULL );

	// Register a callback, which has the option to abort the current operation. This is done by
	// returning a false value in the supplied return code parameter
	//
	///
	static MCallbackId	addCallback( Message, void (*func)( bool* retCode, void* clientData ),
									 void * clientData = NULL,
									 MStatus * ReturnStatus = NULL );
									 
	// Register a callback which has the option to abort the current file IO
	// or modify the file being acted on. By returning a false value in the
	// supplied return code parameter the operation can be aborted. By
	// setting the file path stored in the file parameter, the file being
	// acted on can be modified.
	//
	///
	static MCallbackId	addCallback( Message, void (*func)( bool* retCode, MFileObject& file, void* clientData ),
									 void * clientData = NULL,
									 MStatus * ReturnStatus = NULL );

private:
private:
	static const char* className();
};

#ifdef _WIN32
#pragma warning(default: 4522)
#endif // _WIN32

// *****************************************************************************

#endif /* __cplusplus */
#endif /* _MSceneMessage */