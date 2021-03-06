

#ifndef TRANSITION_H_
#define TRANSITION_H_

// ====================================================================================================================
// ===	INCLUDES
// ====================================================================================================================

// ====================================================================================================================
// ===	NAMESPACES
// ====================================================================================================================

/// \namespace	util
///	\brief		Contains utilitary classes.
namespace util
{
// ====================================================================================================================
// ===	CLASS
// ====================================================================================================================
template<uint8_t n_state, uint8_t n_transition> class State_Machine;

/// \class	Transition
///	\brief	Model a transition in State_Machine.
/// \date	17/04/2014
/// \author	nboutin & bpayen
class Transition
{
	/// Only State_Machine can change a Transition id.
	template<uint8_t n_state, uint8_t n_transition> friend class State_Machine;

public:
	// ============================================================================================================
	// ===	PUBLIC CONSTANTS
	// ============================================================================================================
	static const uint8_t ID_DEFAULT = 0xFF;	///< Default identifier

	// ============================================================================================================
	// ===	PUBLIC DECLARATIONS
	// ============================================================================================================

	///
	/// \brief	Default constructor
	///
	Transition()
		: m_uc_id(ID_DEFAULT)
	{

	}

	///
	/// \brief	Provides identifier
	/// \return	Identifier
	///
	uint8_t getId() const
	{
		// Return
		return (m_uc_id);
	}

protected:
	// ============================================================================================================
	// ===	PROTECTED ATTRIBUTS
	// ============================================================================================================

	uint8_t m_uc_id;	///< Transition identifiant and priority.

private:
	// ============================================================================================================
	// ===	PRIVATE DECLARATIONS
	// ============================================================================================================
	///
	/// \brief	Update Identifier
	/// \param	iu8_id : identifier
	///
	void setId(const uint8_t iu8_id)
	{
		m_uc_id = iu8_id;
	}
};

// ====================================================================================================================
// ===	CLASS
// ====================================================================================================================

/// \class	Transition_True
///	\brief	Model an always true transition in State_Machine.
/// \date	17/04/2014
/// \author	nboutin & bpayen
class Transition_True: public Transition
{
public:
	// ============================================================================================================
	// ===	PUBLIC CONSTANTS
	// ============================================================================================================
	static const uint32_t BIT_DEFAULT = 0; ///< Bit default value

	// ============================================================================================================
	// ===	PUBLIC DECLARATIONS
	// ============================================================================================================
	///
	/// \brief	Provides transition
	/// \return	Transition
	///
	static Transition_True& get()
	{
		static Transition_True inst;
		return inst;
	}

private:
	// ============================================================================================================
	// ===	PRIVATE DECLARATIONS
	// ============================================================================================================
	///
	/// \brief	Force Transition_True to be at id = BIT_DEFAULT and so detected by State_Machine.
	///
	Transition_True()
		: Transition()
	{
		m_uc_id = BIT_DEFAULT;
	}
};

}

#endif	// TRANSITION_H_

// ====================================================================================================================
// ===	END OF FILE
// ====================================================================================================================
