modded class KOTH_HUD : SCR_InfoDisplay
{
	void NotifStealFromRegister(string bonus)
	{
		PlaySuccessNotificationSound();
		Notif("Register opened", ""+bonus+" xp", ""+bonus+" $", 5000);
	}
}