class SCR_StealFromRegister : ScriptedUserAction
{
	protected KOTH_PlayerEventsGameModeComponent playerEventComp;
	override void PerformAction(IEntity pOwnerEntity, IEntity pUserEntity) 
	{
		
		// Return if event is fired by the server
		if (!Replication.IsServer())
			return;
		// Get the user's ID, return if null
		int playerId = GetGame().GetPlayerManager().GetPlayerIdFromControlledEntity(pUserEntity);
		if (playerId == 0)
			return;
		if(playerEventComp == null)
		{
			playerEventComp = KOTH_PlayerEventsGameModeComponent.Cast(GetGame().GetGameMode().FindComponent(KOTH_PlayerEventsGameModeComponent)); 			
		}
		playerEventComp.HandleStealFromRegister(playerId);
	}
	override bool CanBeShownScript(IEntity user)
	{
		return true;
	}
	
	override bool CanBePerformedScript(IEntity user)
	{
		if(playerEventComp == null)
		{
			return true;
		}
		// Disable input if user has already opened a register since his last death
		bool isRegisterAvailable = !playerEventComp.GetHasUserOpenedARegister();
		return isRegisterAvailable;
	}
	

}