class SCR_StealFromRegister : ScriptedUserAction
{
	// properties and methods here
	override void PerformAction(IEntity pOwnerEntity, IEntity pUserEntity) 
	{
		Print("HEERE");
	}
	override bool CanBeShownScript(IEntity user)
	{
		return true;
	}
	
	override bool CanBePerformedScript(IEntity user)
	{
		return true;
	}
}