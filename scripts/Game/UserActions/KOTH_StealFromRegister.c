class SCR_StealFromRegister : ScriptedUserAction
{
	KOTH_PlayerEventsGameModeComponent playerEventComp;
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
		
		// Disable input if user has already opened a register since his last death
		if(playerEventComp == null)
		{
			return true;
		}
		bool isRegisterAvailable = playerEventComp.GetHasUserOpenedARegister();
		Print("Can register be opened : " + isRegisterAvailable);
		return isRegisterAvailable;
	}
	

}