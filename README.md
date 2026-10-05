# defold-rustore-appupdate

Обновление приложения из RuStore без выхода из игры — RuStore AppUpdate SDK для Defold, расширение
`RuStoreAppUpdate`, Lua-модуль `rustoreappupdate` и глобал `RuStoreAppUpdateEnums`. Официальный плагин
[rustore-defold-appupdate](https://gitflic.ru/project/rustore/rustore-defold-appupdate), упакованный в
библиотеку Defold: на GitFlic он ставится копированием папок, отсюда — строкой в `dependencies`.

| | |
|---|---|
| SDK | `ru.rustore.sdk:appupdate:10.5.1` |
| Источник | rustore-defold-appupdate, `master` от 08.09.2026 (`03c35e5`) |
| Нужен core | [defold-rustore-core](https://github.com/maningame/defold-rustore-core) `10.5.0-1` |
| Платформы | Android, Defold 1.9+; на остальных — пустой модуль |
| Документация | [rustore.ru/help/sdk/updates/defold/10-5-1](https://www.rustore.ru/help/sdk/updates/defold/10-5-1) |

## Подключение

В `[project] dependencies` Android-цели (`platforms/<цель>/platform.settings`) —
вместе с core, сам Defold его не подтянет. Манифест и ресурсы не нужны.

```ini
dependencies#N = https://github.com/maningame/defold-rustore-core/archive/refs/tags/10.5.0-1.zip
dependencies#M = https://github.com/maningame/defold-rustore-appupdate/archive/refs/tags/10.5.1-1.zip
```

Только для сборки в RuStore: обновляет из RuStore, в Google Play у обновлений свой механизм.

## Lua

Ответы приходят в каналы через `rustorecore.connect`: `rustore_get_app_update_info_*`,
`rustore_start_update_flow_*`, `rustore_complete_update_failure` и `rustore_on_state_updated` (ход загрузки после
`register_listener`).

```lua
rustorecore.connect("rustore_get_app_update_info_success", on_update_info)
rustoreappupdate.init()
rustoreappupdate.get_appupdateinfo()
```

Сценарии `immediate`, `delayed` и `silent`, перечисления — в документации RuStore и
`extension_rustore_appupdate/lua/*_stub.lua`.

## Отличия от GitFlic

- Заглушка `#else` для платформ кроме Android, как у pay: у RuStore без неё проект с плагином не собирался в
  редакторе. Вне Android `rustoreappupdate` — пустая таблица, вызовы держат за проверкой платформы.

## Обновление с GitFlic

1. `git clone https://gitflic.ru/project/rustore/rustore-defold-appupdate.git`, взять `master` или тег.
2. Заменить `extension_rustore_appupdate` на `appupdate_example/extension_rustore_appupdate` и повторить отличия
   выше.
3. Версия `core` в `versions.json` новее нашей — сначала обновить
   [defold-rustore-core](https://github.com/maningame/defold-rustore-core) и ссылку на него в `game.project`.
4. Коммит `build: rustore appupdate <версия>`, тег — версия SDK. Наша правка поверх той же версии — тег
   `<версия>-1`.

## Лицензия

MIT, © RuStore — [MIT-LICENSE.txt](MIT-LICENSE.txt).
