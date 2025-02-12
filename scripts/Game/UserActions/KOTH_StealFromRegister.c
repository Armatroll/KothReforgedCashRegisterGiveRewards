class SCR_StealFromRegister : ScriptedUserAction
{
	const int BONUS_STEAL_FROM_REGISTER = 100;
	override void PerformAction(IEntity pOwnerEntity, IEntity pUserEntity) 
	{
		
		// Return if event is fired by the server
		if (!Replication.IsServer())
			return;
		// Get the user's ID, return if null
		int playerId = GetGame().GetPlayerManager().GetPlayerIdFromControlledEntity(pUserEntity);
		if (playerId == 0)
			return;
		
		KOTH_PlayerEventsGameModeComponent playerEventComp = KOTH_PlayerEventsGameModeComponent.Cast(GetGame().GetGameMode().FindComponent(KOTH_PlayerEventsGameModeComponent)); 
		playerEventComp.HandleStealFromRegister(playerId);
	}
	override bool CanBeShownScript(IEntity user)
	{
		return true;
	}
	
	override bool CanBePerformedScript(IEntity user)
	{
		return true;
	}
	void HandleStealFromRegister(int playerId)
	{
		
		// NotificationHelper tools
		/*
		KOTH_SCR_PlayerProfileComponent profileComp = KOTH_SCR_PlayerProfileComponent.Cast(m_playerManager.GetPlayerController(playerId).FindComponent(KOTH_SCR_PlayerProfileComponent));
		 profile related interactions tools
		KOTH_PlayerProfileJson profile = m_kothBackendApi.m_CurrentProfileList.Get(playerUID);
		//RegisterInteraction rInteraction = new RegisterInteraction();
		profile.AddXp(BONUS_STEAL_FROM_REGISTER);
		profile.AddMoney(BONUS_STEAL_FROM_REGISTER);
		profileComp.FlushToilet("Stole from the register : 100$/xp");*/
	}
}