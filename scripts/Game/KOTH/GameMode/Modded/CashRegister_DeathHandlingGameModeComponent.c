modded class KOTH_DeathHandlingGameModeComponent : SCR_BaseGameModeComponent
{
	override void CleanupPlayer(KOTH_DeathEvent deathEvent)
	{
		deathEvent.playerProfileComp.ResetHasPlayerOpenedARegister();
		// call overriden function
		super.CleanupPlayer(deathEvent);
	}
	
}